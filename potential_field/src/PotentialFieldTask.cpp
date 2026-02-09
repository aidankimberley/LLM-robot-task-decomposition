#include "rclcpp/rclcpp.hpp"
#include "potential_field/PotentialFieldTask.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"
#include <Eigen/Dense>

//Potential Field just for the end effector


using Move3d = highlevel_interfaces::srv::Move3d;
//PUBLIC
PotentialFieldTask::PotentialFieldTask(const std::string& name): rclcpp::Node(name){

    this->declare_parameter("robot_pose_topic", "/gen3/feedback/pose");
    this->declare_parameter("target_twist_topic", "/gen3/reference/twist");
    this->declare_parameter("move_to_service", "/planner/move_to");
    this->declare_parameter("maximum_linear_velocity", 1.0);
    this->declare_parameter("k_att", 5.0);
   
    auto robot_pose_topic = this->get_parameter("robot_pose_topic").as_string();
    auto target_twist_topic = this->get_parameter("target_twist_topic").as_string();
    auto move_to_service = this->get_parameter("move_to_service").as_string();
    v_max_ = this->get_parameter("maximum_linear_velocity").as_double();
    k_att_ = this->get_parameter("k_att").as_double();

    //create subscriber
    subscriber_ = this->create_subscription<geometry_msgs::msg::Pose>(
        robot_pose_topic,
        5,
        std::bind(&PotentialFieldTask::sub_callback, this, std::placeholders::_1)
    );
    //create server
    server_ = this->create_service<Move3d>(move_to_service,
        std::bind(&PotentialFieldTask::server_callback, this, std::placeholders::_1, std::placeholders::_2)
    );

    //create 2 publishers
    velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(target_twist_topic, 1);
    done_publisher_ = this->create_publisher<std_msgs::msg::Bool>("/planner/done", 1);
    
    //define private variables
    eps_ = 0.1; //m
}

void PotentialFieldTask::update(){
    if (recieved_first_pose_ && recieved_first_service_call_){
        RCLCPP_DEBUG(this->get_logger(), "Target recieved, calculating potential field...");
        Eigen::Vector3d target(x_target_, y_target_, z_target_);
        Eigen::Vector3d robot(x_robot_, y_robot_, z_robot_);
        Eigen::Vector3d difference = target - robot;
        double distance = difference.norm();
        if (distance < eps_){
            done_msg_.data = true;
            done_publisher_->publish(done_msg_);
        }
        else{
            done_msg_.data = false;
            done_publisher_->publish(done_msg_);
        }

        Eigen::Vector3d x_dot_unscaled = k_att_ * difference;
        double norm = x_dot_unscaled.norm();
        if (norm > v_max_ && norm>0.0){
            Eigen::Vector3d x_dot = x_dot_unscaled / norm * v_max_;
            velocity_msg_.linear.x = x_dot[0];
            velocity_msg_.linear.y = x_dot[1];
            velocity_msg_.linear.z = x_dot[2];
        }
        else{
            Eigen::Vector3d x_dot = x_dot_unscaled;
            velocity_msg_.linear.x = x_dot[0];
            velocity_msg_.linear.y = x_dot[1];
            velocity_msg_.linear.z = x_dot[2];
        }
        
        velocity_publisher_->publish(velocity_msg_);
        RCLCPP_DEBUG(this->get_logger(), "Velocity published: x=%f, y=%f, z=%f", velocity_msg_.linear.x, velocity_msg_.linear.y, velocity_msg_.linear.z);
    }
    else{
        RCLCPP_DEBUG(this->get_logger(), "No target recieved, publishing zero velocity...");
        velocity_msg_.linear.x = 0.0;
        velocity_msg_.linear.y = 0.0;
        velocity_msg_.linear.z = 0.0;
        done_msg_.data = true;
        done_publisher_->publish(done_msg_);
        velocity_publisher_->publish(velocity_msg_);
        RCLCPP_DEBUG(this->get_logger(), "Zero velocity published");
    }
}
//PRIVATE
void PotentialFieldTask::sub_callback(const geometry_msgs::msg::Pose::SharedPtr msg){
    x_robot_ = msg->position.x;
    y_robot_ = msg->position.y;
    z_robot_ = msg->position.z;
    recieved_first_pose_ = true;
}

void PotentialFieldTask::server_callback(const std::shared_ptr<Move3d::Request> request,
    std::shared_ptr<Move3d::Response> response){
        RCLCPP_INFO(this->get_logger(), "Recieved request: x=%f, y=%f, z=%f", request->x, request->y, request->z);
        x_target_ = request->x;
        y_target_ = request->y;
        z_target_ = request->z;
        recieved_first_service_call_ = true;
        if (!recieved_first_pose_){
            response->success = false;
        }
        else{
            response->success = true;
        }
    }


//create node




// subscribe to a topic 

// in callback, read the x,y position of the robot using msg.poses and ... save the current position of the robot in a variable
