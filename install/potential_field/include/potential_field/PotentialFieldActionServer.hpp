#include <rclcpp/rclcpp.hpp>
#include <rclcpp/logger.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include <highlevel_interfaces/action/pose_command.hpp>

#include <Eigen/Geometry>

using PoseCommandAction = highlevel_interfaces::action::PoseCommand ; 
using PoseCommandGoalHandle = rclcpp_action::ServerGoalHandle<PoseCommandAction>;

class PotentialFieldActionServer : public rclcpp::Node {

	public:
		PotentialFieldActionServer() ;

	private:

		rclcpp::Logger logger_ ; 

		rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, [[maybe_unused]] std::shared_ptr<const PoseCommandAction::Goal> goal) ;
		rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<PoseCommandGoalHandle> goal_handle) ;
		void handle_accepted(const std::shared_ptr<PoseCommandGoalHandle> goal_handle) ;
		void execute_action(const std::shared_ptr<PoseCommandGoalHandle> goal_handle) ;

  		rclcpp_action::Server<PoseCommandAction>::SharedPtr action_server_ ;
		std::shared_ptr<PoseCommandAction::Feedback> pose_command_feedback_ ;
		std::shared_ptr<PoseCommandAction::Result> pose_command_response_ ; 
		std::string pose_command_action_name_ = "/planner/move_pose" ; // or whatever action name

        rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr pose_subscriber_; 
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr reference_twist_publisher_;

        void sub_callback(const geometry_msgs::msg::Pose::SharedPtr msg);

        bool recieved_first_pose_ = false;
        double x_robot_;
        double y_robot_;
        double z_robot_;
        double roll_robot_{0.0};
        double pitch_robot_{0.0};
        double yaw_robot_{0.0};
        double x_target_;
        double y_target_;
        double z_target_;
        double pitch_target_;
        double roll_target_;
        double yaw_target_;

        geometry_msgs::msg::Twist velocity_msg_;
        geometry_msgs::msg::Pose default_pose_target_;

        double k_att_{5.0};
        double v_max_{1.0};
        double w_max_{1.0};
        double done_translation_{0.05};
        double done_orientation_{0.1};
        double timeout_s_{5.0};
        bool use_orientation_{true};

        Eigen::Quaterniond q_robot_;
        Eigen::Quaterniond q_target_;
};

