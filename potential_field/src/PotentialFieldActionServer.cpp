#include "potential_field/PotentialFieldActionServer.hpp"

#include <Eigen/Geometry>

#include <algorithm>
#include <cmath>

#include <chrono>
#include <thread>

PotentialFieldActionServer::PotentialFieldActionServer()
    : rclcpp::Node("potential_field_action_server"), logger_(this->get_logger()) {
  this->declare_parameter("robot_pose_topic", "/gen3/feedback/pose");
  this->declare_parameter("target_twist_topic", "/gen3/reference/twist");
  this->declare_parameter("k_att", 5.0);
  this->declare_parameter("maximum_linear_velocity", 1.0);
  this->declare_parameter("maximum_angular_velocity", 1.0);
  this->declare_parameter("done_translation", 0.05);
  this->declare_parameter("done_orientation", 0.1);
  this->declare_parameter("timeout_s", 5.0);
  this->declare_parameter("use_orientation", true);
  this->declare_parameter("action_name", pose_command_action_name_);

  auto robot_pose_topic = this->get_parameter("robot_pose_topic").as_string();
  auto target_twist_topic = this->get_parameter("target_twist_topic").as_string();
  k_att_ = this->get_parameter("k_att").as_double();
  v_max_ = this->get_parameter("maximum_linear_velocity").as_double();
  w_max_ = this->get_parameter("maximum_angular_velocity").as_double();
  done_translation_ = this->get_parameter("done_translation").as_double();
  done_orientation_ = this->get_parameter("done_orientation").as_double();
  timeout_s_ = this->get_parameter("timeout_s").as_double();
  use_orientation_ = this->get_parameter("use_orientation").as_bool();
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
  
  default_pose_target_.position.x = 0.5;
  default_pose_target_.position.y = 0.2;
  default_pose_target_.position.z = 0.5;
  //Eigen::Quaterniond quaternion_default_pose_target = Eigen::AngleAxisd(0, Eigen::Vector3d::UnitZ()) * Eigen::AngleAxisd(0, Eigen::Vector3d::UnitY()) * Eigen::AngleAxisd(0, Eigen::Vector3d::UnitX());
  Eigen::Quaterniond quaternion_default_pose_target = Eigen::Quaterniond::Identity();
  default_pose_target_.orientation.w = quaternion_default_pose_target.w();
  default_pose_target_.orientation.x = quaternion_default_pose_target.x();
  default_pose_target_.orientation.y = quaternion_default_pose_target.y();
  default_pose_target_.orientation.z = quaternion_default_pose_target.z();

  RCLCPP_INFO(logger_, "PotentialFieldActionServer ready on action '%s'",
              pose_command_action_name_.c_str());

}

void PotentialFieldActionServer::homing() {
  //RCLCPP_INFO(this->get_logger(), "Homing...");
  // Translation error (meters)
  const Eigen::Vector3d x_goal_trans(default_pose_target_.position.x, default_pose_target_.position.y, default_pose_target_.position.z);
  const Eigen::Vector3d x_robot_trans(x_robot_, y_robot_, z_robot_);
  Eigen::Vector3d omega = Eigen::Vector3d::Zero();

  q_target_ = Eigen::Quaterniond(
    default_pose_target_.orientation.w,
    default_pose_target_.orientation.x,
    default_pose_target_.orientation.y,
    default_pose_target_.orientation.z
  );
  q_target_.normalize();

  Eigen::Quaterniond q_diff = q_target_ * q_robot_.conjugate();
  q_diff.normalize();
  if (q_diff.w() < 0.0) {
    q_diff.coeffs() *= -1.0;
  }

  omega = 2.0 * k_att_ * Eigen::Vector3d(q_diff.x(), q_diff.y(), q_diff.z());
  const double w_norm = omega.norm();
  if (w_norm > w_max_ && w_norm > 0.0) {
    omega = (omega / w_norm) * w_max_;
  }

  Eigen::Vector3d v_lin = k_att_ * (x_goal_trans - x_robot_trans);
  const double v_norm = v_lin.norm();
  if (v_norm > v_max_ && v_norm > 0.0) {
    v_lin = (v_lin / v_norm) * v_max_;
  }

  velocity_msg_.linear.x = v_lin[0];
  velocity_msg_.linear.y = v_lin[1];
  velocity_msg_.linear.z = v_lin[2];
  velocity_msg_.angular.x = omega[0];
  velocity_msg_.angular.y = omega[1];
  velocity_msg_.angular.z = omega[2];
  //RCLCPP_INFO(logger_, "Velocity: %f, %f, %f", velocity_msg_.linear.x, velocity_msg_.linear.y, velocity_msg_.linear.z);
  //RCLCPP_INFO(logger_, "Angular Velocity: %f, %f, %f", velocity_msg_.angular.x, velocity_msg_.angular.y, velocity_msg_.angular.z);
  reference_twist_publisher_->publish(velocity_msg_);
  }


void PotentialFieldActionServer::sub_callback(const geometry_msgs::msg::Pose::SharedPtr msg) {
  x_robot_ = msg->position.x;
  y_robot_ = msg->position.y;
  z_robot_ = msg->position.z;
  
  q_robot_ = Eigen::Quaterniond(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z).normalized();


  const Eigen::Vector3d rpy = q_robot_.toRotationMatrix().eulerAngles(0, 1, 2);
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

  // Validate goal bounds for position and orientation
  if (
      goal->z < 0.01 || goal->z > 0.8 ||
      goal->x < -0.8 || goal->x > 0.8 ||
      goal->y < -0.8 || goal->y > 0.8 ||
      goal->roll < -M_PI || goal->roll > M_PI ||
      goal->pitch < -M_PI || goal->pitch > M_PI ||
      goal->yaw < -M_PI || goal->yaw > M_PI
  ) {
    RCLCPP_WARN(logger_, "Rejecting goal: one or more fields out of bounds "
                         "[x: %.2f, y: %.2f, z: %.2f, roll: %.2f, pitch: %.2f, yaw: %.2f]",
                         goal->x, goal->y, goal->z, goal->roll, goal->pitch, goal->yaw);
    return rclcpp_action::GoalResponse::REJECT;
  }
  active_action_call_ = true;
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse PotentialFieldActionServer::handle_cancel(
    const std::shared_ptr<PoseCommandGoalHandle> goal_handle) {
  (void)goal_handle;
  RCLCPP_INFO(logger_, "Received cancel request");
  active_action_call_ = false;
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

  default_pose_target_.position.x = x_target_;
  default_pose_target_.position.y = y_target_;
  default_pose_target_.position.z = z_target_;
  Eigen::Quaterniond quaternion_default_pose_target = Eigen::AngleAxisd(yaw_target_, Eigen::Vector3d::UnitZ()) *
                  Eigen::AngleAxisd(pitch_target_, Eigen::Vector3d::UnitY()) *
                  Eigen::AngleAxisd(roll_target_, Eigen::Vector3d::UnitX());
  default_pose_target_.orientation.w = quaternion_default_pose_target.w();
  default_pose_target_.orientation.x = quaternion_default_pose_target.x();
  default_pose_target_.orientation.y = quaternion_default_pose_target.y();
  default_pose_target_.orientation.z = quaternion_default_pose_target.z();
  
  rclcpp::Rate rate(500.0);

  while (rclcpp::ok()) {
    if (goal_handle->is_canceling()) {
      // reference_twist_publisher_->publish(geometry_msgs::msg::Twist());
      active_action_call_ = false;
      pose_command_response_->success = false;
      pose_command_response_->message = "Goal canceled";

      goal_handle->canceled(pose_command_response_);
      return;
    }

    const double elapsed = (this->now() - start_time).seconds();
    const double elapsed_ms = (this->now() - start_time).nanoseconds()/1e6;
    pose_command_feedback_->time_elapsed = elapsed;
    if (elapsed > timeout_s_) {
      //reference_twist_publisher_->publish(geometry_msgs::msg::Twist());//publishes zero velocity
      pose_command_response_->success = false;
      pose_command_response_->message = "Timed out";
      goal_handle->abort(pose_command_response_);
      active_action_call_ = false;
      return;
    }

    // Translation error (meters)
    const Eigen::Vector3d x_goal_trans(x_target_, y_target_, z_target_);
    const Eigen::Vector3d x_robot_trans(x_robot_, y_robot_, z_robot_);
    const double trans_err = (x_goal_trans - x_robot_trans).norm();

    double orient_err = 0.0;
    Eigen::Vector3d omega = Eigen::Vector3d::Zero();
    // Orientation error (radians), computed on SO(3) via quaternion difference
    q_target_ = Eigen::AngleAxisd(yaw_target_, Eigen::Vector3d::UnitZ()) *
                Eigen::AngleAxisd(pitch_target_, Eigen::Vector3d::UnitY()) *
                Eigen::AngleAxisd(roll_target_, Eigen::Vector3d::UnitX());
    q_target_.normalize();

    Eigen::Quaterniond q_diff = q_target_ * q_robot_.conjugate();
    q_diff.normalize();
    if (q_diff.w() < 0.0) {
      q_diff.coeffs() *= -1.0;
    }
    
    orient_err = 2.0 * acos(abs(q_robot_.dot(q_target_)));

    // const double w = std::clamp(std::abs(q_diff.w()), 0.0, 1.0);
    // orient_err = 2.0 * std::acos(w);

    omega = 2.0 * k_att_ * Eigen::Vector3d(q_diff.x(), q_diff.y(), q_diff.z());
    const double w_norm = omega.norm();
    if (w_norm > w_max_ && w_norm > 0.0) {
      omega = (omega / w_norm) * w_max_;
    }
    

    // const Eigen::Vector3d x_robot_rpy(roll_robot_, pitch_robot_, yaw_robot_);

    // const double orient_err = (x_goal_rpy - x_robot_rpy).norm();
    pose_command_feedback_->distance_translation = trans_err;
    pose_command_feedback_->distance_orientation = orient_err;
    goal_handle->publish_feedback(pose_command_feedback_);
    // if (trans_err < done_translation_){
    //   RCLCPP_INFO(logger_, "Translation error: %f", trans_err);
    // }
    // if (orient_err < done_orientation_){
    //   RCLCPP_INFO(logger_, "Orientation error: %f", orient_err);
    // }
    // RCLCPP_INFO(logger_, "orientation error: %f", orient_err);
    if (trans_err < done_translation_ && orient_err < done_orientation_) {
      // velocity_msg_ = geometry_msgs::msg::Twist(); //initializes to zero
      // reference_twist_publisher_->publish(velocity_msg_);

      pose_command_response_->success = true;
      pose_command_response_->message = "Reached target";
      goal_handle->succeed(pose_command_response_);
      active_action_call_ = false;
      return;
    }

    Eigen::Vector3d v_lin = k_att_ * (x_goal_trans - x_robot_trans);
    const double v_norm = v_lin.norm();
    if (v_norm > v_max_ && v_norm > 0.0) {
      v_lin = (v_lin / v_norm) * v_max_;
    }

    velocity_msg_.linear.x = v_lin[0];
    velocity_msg_.linear.y = v_lin[1];
    velocity_msg_.linear.z = v_lin[2];
    velocity_msg_.angular.x = omega[0];
    velocity_msg_.angular.y = omega[1];
    velocity_msg_.angular.z = omega[2];
    //RCLCPP_INFO(logger_, "Velocity: %f, %f, %f", velocity_msg_.linear.x, velocity_msg_.linear.y, velocity_msg_.linear.z);
    //RCLCPP_INFO(logger_, "Angular Velocity: %f, %f, %f", velocity_msg_.angular.x, velocity_msg_.angular.y, velocity_msg_.angular.z);
    reference_twist_publisher_->publish(velocity_msg_);

    rate.sleep();
  }
}
