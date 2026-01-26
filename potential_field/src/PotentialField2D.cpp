#include "rclcpp/rclcpp.hpp"
#include "potential_field/PotentialField2D.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"
#include <Eigen/Dense>



//TODO: FIX THE SERVICE FUNCTIONALITY

using Move2d = highlevel_interfaces::srv::Move2d;
//PUBLIC
PotentialField2D::PotentialField2D(const std::string& name): rclcpp::Node(name){
    subscriber_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
        "/husky/platform/pose",
        5,
        std::bind(&PotentialField2D::sub_callback, this, std::placeholders::_1)
    );

    server_ = this->create_service<Move2d>("/planner/move_to",
        std::bind(&PotentialField2D::server_callback, this, std::placeholders::_1, std::placeholders::_2)
    );
    // client_ = this->create_client<Move2d>("Move2d");
    // RCLCPP_INFO(this->get_logger(), "A service Client is created");
    // RCLCPP_INFO(this->get_logger(),"Waiting for service");

    velocity_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/planner/velocity", 1);
    done_publisher_ = this->create_publisher<std_msgs::msg::Bool>("/planner/done", 1);
    
    velocity_msg_.data.resize(2);
}

void PotentialField2D::update(){
    if (recieved_first_pose_ && recieved_first_service_call_){
        Eigen::Vector2d target(x_target_, y_target_);
        Eigen::Vector2d robot(x_robot_, y_robot_);
        Eigen::Vector2d difference = target - robot;
        double distance = difference.norm();
        if (distance < eps_){
            done_msg_.data = true;
            done_publisher_->publish(done_msg_);
        }
        else{
            done_msg_.data = false;
            done_publisher_->publish(done_msg_);
        }

        Eigen::Vector2d x_dot_unscaled = k_att_ * difference;
        double norm = x_dot_unscaled.norm();
        if (norm > 0.0) {
            Eigen::Vector2d x_dot = x_dot_unscaled / norm * v_max_;
            velocity_msg_.data[0] = x_dot[0];
            velocity_msg_.data[1] = x_dot[1];
        } else {
            velocity_msg_.data[0] = 0.0;
            velocity_msg_.data[1] = 0.0;
        }
        velocity_publisher_->publish(velocity_msg_);
    }
    else{
        velocity_msg_.data[0] = 0.0;
        velocity_msg_.data[1] = 0.0;
        done_msg_.data = true;
        done_publisher_->publish(done_msg_);
        velocity_publisher_->publish(velocity_msg_);
    }
}
//PRIVATE
void PotentialField2D::sub_callback(const geometry_msgs::msg::PoseArray::SharedPtr msg){
    x_robot_ = msg->poses[5].position.x;
    y_robot_ = msg->poses[5].position.y;
    recieved_first_pose_ = true;
}
//void PotentialField2D::client_callback(const )
void PotentialField2D::server_callback(const std::shared_ptr<Move2d::Request> request,
    std::shared_ptr<Move2d::Response> response){
        //TODO: FILL THIS IN
        RCLCPP_INFO(this->get_logger(), "Recieved request: x=%f, y=%f", request->x, request->y);
        x_target_ = request->x;
        y_target_ = request->y;
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
