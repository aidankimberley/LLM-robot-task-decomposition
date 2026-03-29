#include "potential_field/PotentialFieldActionServer.hpp"

#include <Eigen/Geometry>

#include <chrono>
#include <thread>

PotentialFieldActionServer::PotentialFieldActionServer()
    : rclcpp::Node("potential_field_action_server"), logger_(this->get_logger()) {
  this->declare_parameter("robot_pose_topic", "/gen3/feedback/pose");
  this->declare_parameter("target_twist_topic", "/gen3/reference/twist");
  this->declare_parameter("k_att", 5.0);
  this->declare_parameter("done_translation", 0.05);
  this->declare_parameter("done_orientation", 0.1);
  this->declare_parameter("timeout_s", 5.0);
  this->declare_parameter("action_name", pose_command_action_name_);

  auto robot_pose_topic = this->get_parameter("robot_pose_topic").as_string();
  auto target_twist_topic = this->get_parameter("target_twist_topic").as_string();
  k_att_ = this->get_parameter("k_att").as_double();
  done_translation_ = this->get_parameter("done_translation").as_double();
  done_orientation_ = this->get_parameter("done_orientation").as_double();
  timeout_s_ = this->get_parameter("timeout_s").as_double();
  pose_command_action_name_ = this->get_parameter("action_name").as_string();

  pose_command_feedback_ = std::make_shared<PoseCommandAction::Feedback>();
  pose_command_response_ = std::make_shared<PoseCommandAction::Result>();

  pose_subscriber_ = this->create_subscription<geometry_msgs::msg::Pose>(
      robot_pose_topic, 5,
      std::bind(&PotentialFieldActionServer::sub_callback, this, std::placeholders::_1));

  reference_twist_publisher_ =
      this->create_publisher<geometry_msgs::msg::Twist>(target_twist_topic, 1);

  action_server_ = rclcpp_action::create_server<PoseCommandAction>(
      this, pose_command_action_name_,
      std::bind(&PotentialFieldActionServer::handle_goal, this, std::placeholders::_1,
                std::placeholders::_2),
      std::bind(&PotentialFieldActionServer::handle_cancel, this, std::placeholders::_1),
      std::bind(&PotentialFieldActionServer::handle_accepted, this, std::placeholders::_1));

  RCLCPP_INFO(logger_, "PotentialFieldActionServer ready on action '%s'",
              pose_command_action_name_.c_str());
}

void PotentialFieldActionServer::sub_callback(const geometry_msgs::msg::Pose::SharedPtr msg) {
  x_robot_ = msg->position.x;
  y_robot_ = msg->position.y;
  z_robot_ = msg->position.z;

  const Eigen::Quaterniond q(msg->orientation.w, msg->orientation.x, msg->orientation.y,
                            msg->orientation.z);
  const Eigen::Vector3d rpy = q.toRotationMatrix().eulerAngles(0, 1, 2);
  roll_robot_ = rpy[0];
  pitch_robot_ = rpy[1];
  yaw_robot_ = rpy[2];

  recieved_first_pose_ = true;
}

rclcpp_action::GoalResponse PotentialFieldActionServer::handle_goal(
    const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const PoseCommandAction::Goal> goal) {
  (void)uuid;

  if (!recieved_first_pose_) {
    RCLCPP_WARN(logger_, "Rejecting goal: have not received feedback pose yet");
    return rclcpp_action::GoalResponse::REJECT;
  }

  if (goal->z < 0.01) {
    RCLCPP_WARN(logger_, "Rejecting goal: z too low");
    return rclcpp_action::GoalResponse::REJECT;
  }

  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse PotentialFieldActionServer::handle_cancel(
    const std::shared_ptr<PoseCommandGoalHandle> goal_handle) {
  (void)goal_handle;
  RCLCPP_INFO(logger_, "Received cancel request");
  return rclcpp_action::CancelResponse::ACCEPT;
}

void PotentialFieldActionServer::handle_accepted(
    const std::shared_ptr<PoseCommandGoalHandle> goal_handle) {
  std::thread{
      std::bind(&PotentialFieldActionServer::execute_action, this, std::placeholders::_1),
      goal_handle}
      .detach();
}

void PotentialFieldActionServer::execute_action(
    const std::shared_ptr<PoseCommandGoalHandle> goal_handle) {
  const auto start_time = this->now();
  const auto goal = goal_handle->get_goal();

  x_target_ = goal->x;
  y_target_ = goal->y;
  z_target_ = goal->z;
  roll_target_ = goal->roll;
  pitch_target_ = goal->pitch;
  yaw_target_ = goal->yaw;

  rclcpp::Rate rate(500.0);

  while (rclcpp::ok()) {
    if (goal_handle->is_canceling()) {
      pose_command_response_->success = false;
      pose_command_response_->message = "Goal canceled";
      goal_handle->canceled(pose_command_response_);
      return;
    }

    const double elapsed = (this->now() - start_time).seconds();
    pose_command_feedback_->time_elapsed = elapsed;
    if (elapsed > timeout_s_) {
      pose_command_response_->success = false;
      pose_command_response_->message = "Timed out";
      goal_handle->abort(pose_command_response_);
      return;
    }

    const Eigen::Vector3d x_goal_trans(x_target_, y_target_, z_target_);
    const Eigen::Vector3d x_goal_rpy(roll_target_, pitch_target_, yaw_target_);
    const Eigen::Vector3d x_robot_trans(x_robot_, y_robot_, z_robot_);
    const Eigen::Vector3d x_robot_rpy(roll_robot_, pitch_robot_, yaw_robot_);

    const double trans_err = (x_goal_trans - x_robot_trans).norm();
    const double orient_err = (x_goal_rpy - x_robot_rpy).norm();
    pose_command_feedback_->distance_translation = trans_err;
    pose_command_feedback_->distance_orientation = orient_err;
    goal_handle->publish_feedback(pose_command_feedback_);

    if (trans_err < done_translation_ && orient_err < done_orientation_) {
      velocity_msg_ = geometry_msgs::msg::Twist();
      reference_twist_publisher_->publish(velocity_msg_);

      pose_command_response_->success = true;
      pose_command_response_->message = "Reached target";
      goal_handle->succeed(pose_command_response_);
      return;
    }

    Eigen::Vector3d v_lin = k_att_ * (x_goal_trans - x_robot_trans);
    const double v_norm = v_lin.norm();
    if (v_norm > v_max_ && v_norm > 0.0) {
      v_lin = (v_lin / v_norm) * v_max_;
    }
    const Eigen::Vector3d v_ang = k_att_ * (x_goal_rpy - x_robot_rpy);

    velocity_msg_.linear.x = v_lin[0];
    velocity_msg_.linear.y = v_lin[1];
    velocity_msg_.linear.z = v_lin[2];
    velocity_msg_.angular.x = v_ang[0];
    velocity_msg_.angular.y = v_ang[1];
    velocity_msg_.angular.z = v_ang[2];
    RCLCPP_INFO(logger_, "Velocity: %f, %f, %f", velocity_msg_.linear.x, velocity_msg_.linear.y, velocity_msg_.linear.z);
    RCLCPP_INFO(logger_, "Angular Velocity: %f, %f, %f", velocity_msg_.angular.x, velocity_msg_.angular.y, velocity_msg_.angular.z);
    reference_twist_publisher_->publish(velocity_msg_);

    rate.sleep();
  }
}
