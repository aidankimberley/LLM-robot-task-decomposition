#include "rclcpp/rclcpp.hpp"
#include "potential_field/PotentialFieldJoint.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"
#include <Eigen/Dense>
#include <sstream>

using Trigger = std_srvs::srv::Trigger;
//PUBLIC
PotentialField2D::PotentialField2D(const std::string& name): rclcpp::Node(name){
    //create subscriber
    // subscriber_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
    //     "/husky/platform/pose",
    //     5,
    //     std::bind(&PotentialField2D::sub_callback, this, std::placeholders::_1)
    // );
    joint_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "/joint_states",
        5,
        std::bind(&PotentialField2D::joint_callback, this, std::placeholders::_1)
    );
    this->declare_parameter<std::string>("reference_joint_vel_topic", "/gen3/reference/velocity");
    auto reference_joint_vel_topic = this->get_parameter("reference_joint_vel_topic").as_string();

    //create homing server
    //create server
    //NOTE: must pass in 'this' to member functions, see bind() below
    homing_server_ = this->create_service<Trigger>("/planner/homing", std::bind(&PotentialField2D::homing_callback, this, std::placeholders::_1, std::placeholders::_2));
    // server_ = this->create_service<Move2d>("/planner/move_to",
    //     std::bind(&PotentialField2D::server_callback, this, std::placeholders::_1, std::placeholders::_2)
    // );
    // client_ = this->create_client<Move2d>("Move2d");
    // RCLCPP_INFO(this->get_logger(), "A service Client is created");
    // RCLCPP_INFO(this->get_logger(),"Waiting for service");
    reference_joint_vel_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(reference_joint_vel_topic, 1);
    //create 2 publishers
    joint_velocity_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/planner/joint_velocity",1);
    //velocity_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/planner/velocity", 1);
    done_publisher_ = this->create_publisher<std_msgs::msg::Bool>("/planner/done", 1);

    reference_joint_pose_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/gen3/reference/position", 1);
    
    // Initialize velocity message size (7 joints)
    joint_velocity_msg_.data.resize(7);
    reference_joint_pose_.data.resize(7);
    //velocity_msg_.data.resize(2);
    
    if (!readParameters()){
        RCLCPP_ERROR(this->get_logger(), "Failed to read parameters");
        rclcpp::shutdown();
    }
    else{
        RCLCPP_INFO(this->get_logger(), "Parameters read successfully");
    }

}

bool PotentialField2D::readParameters(){
    RCLCPP_DEBUG(this->get_logger(), "Read Parameters Called");
    double k_att_default = 5.0;
    std::vector<double> maximum_joint_velocity_default = {1.0,1.0,1.0,1.0,1.0,1.0,1.0};
    std::vector<double> default_joint_position_default = {0.0,1.54,0.0,1.54,0.0,1.54,0.0};
    double done_threshold_default = 0.05;

    this->declare_parameter<double>("k_att", k_att_default);
    this->declare_parameter<std::vector<double>>("maximum_joint_velocity", maximum_joint_velocity_default);
    this->declare_parameter<std::vector<double>>("default_joint_position", default_joint_position_default);
    this->declare_parameter<double>("done_threshold", done_threshold_default);
  
    dt_ = 1 / 500;

    if (!this->get_parameter("k_att", k_att_)){
        RCLCPP_WARN(this->get_logger(), "Failed to get parameter k_att, setting to default value");
    }
    else{
        this->k_att_ = this->get_parameter("k_att").as_double();
        RCLCPP_INFO(this->get_logger(), "k_att: %f", k_att_);
    }

    if (!this->get_parameter("maximum_joint_velocity", maximum_joint_velocity_vec_)){
        RCLCPP_WARN(this->get_logger(), "Failed to get parameter maximum_joint_velocity, setting to default value");
        maximum_joint_velocity_vec_ = maximum_joint_velocity_default;
        maximum_joint_velocity_ = Eigen::VectorXd::Zero(7);
        for (int i = 0; i < 7; i++){
            maximum_joint_velocity_[i] = maximum_joint_velocity_default.at(i);
        }
    }
    else{
        RCLCPP_INFO(this->get_logger(), "Got max joint vel reading");
        int param_size = maximum_joint_velocity_vec_.size();
        maximum_joint_velocity_ = Eigen::VectorXd::Zero(param_size);
        for (int i = 0; i < param_size; i++){
            maximum_joint_velocity_[i] = maximum_joint_velocity_vec_.at(i);
        }
        
        RCLCPP_INFO_STREAM(this->get_logger(), "maximum_joint_velocity (type: " << typeid(maximum_joint_velocity_).name() << "): " << maximum_joint_velocity_.transpose());
    }


    if (!this->get_parameter("default_joint_position", default_joint_position_vec_)){
        RCLCPP_WARN(this->get_logger(), "Failed to get parameter default_joint_position, setting to default value");
        default_joint_position_vec_ = default_joint_position_default;
        default_joint_position_ = Eigen::VectorXd::Zero(7);
        for (int i = 0; i < 7; i++){
            default_joint_position_[i] = default_joint_position_default.at(i);
        }
    }
    else{
        int param_size2 = default_joint_position_vec_.size();
        default_joint_position_ = Eigen::VectorXd::Zero(param_size2);
        for (int i = 0; i < param_size2; i++){
            default_joint_position_[i] = default_joint_position_vec_.at(i);
        }
        
        RCLCPP_INFO_STREAM(this->get_logger(), "default_joint_position: " << default_joint_position_.transpose());
    }
    
    if (!this->get_parameter("done_threshold", done_threshold_)){
        RCLCPP_WARN(this->get_logger(), "Failed to get parameter done_threshold, setting to default value");
        done_threshold_ = done_threshold_default;
    }
    else{
        RCLCPP_INFO(this->get_logger(), "done_threshold: %f", done_threshold_);
    }

    return true;
}

void PotentialField2D::update(){
    //compute joint vel, using potential field and then publish this vel to /planner/joint_velcity you dont have to 
    //normalize the vel by the norm, instead, cap the vel at max joint vel.

    if(recieved_first_pose_){
        Eigen::VectorXd joint_pos = Eigen::VectorXd::Zero(joint_positions_.size());
        for (size_t i = 0; i < joint_positions_.size(); i++){
            joint_pos[i] = joint_positions_[i];
        }
        
        Eigen::VectorXd difference = default_joint_position_ - joint_pos;
        if (difference.lpNorm<Eigen::Infinity>() < done_threshold_){
            //checking if any singular entry is larger than the threshold
            done_msg_.data = true;
            done_publisher_->publish(done_msg_);
        }
        else{
            done_msg_.data = false;
            done_publisher_->publish(done_msg_);
        }            

        Eigen::VectorXd x_dot_unscaled = k_att_ * difference;
        Eigen::VectorXd x_dot = x_dot_unscaled;

        Eigen::VectorXd q_ref = joint_pos + x_dot * dt_; 
        //check if any joints are moving too fast:
        for (int i = 0; i < (int)maximum_joint_velocity_.size(); i++){
            if (x_dot_unscaled(i) > maximum_joint_velocity_(i)){
                x_dot(i) = maximum_joint_velocity_(i);             
            }
            else if (x_dot_unscaled(i) < -maximum_joint_velocity_(i)){
                x_dot(i) = -maximum_joint_velocity_(i);
            }
        }
        for (int i = 0; i < (int)x_dot.size(); i++){
            joint_velocity_msg_.data[i] = x_dot(i);
            reference_joint_pose_.data[i] = q_ref(i);
        }
        
        reference_joint_vel_publisher_->publish(joint_velocity_msg_);
        reference_joint_pose_publisher_ -> publish(reference_joint_pose_);

        RCLCPP_DEBUG(this->get_logger(), "Reference joint velocity published:");
    }

    if (recieved_first_pose_ && recieved_first_service_call_){
        // Convert std::vector to Eigen::VectorXd for math
        Eigen::VectorXd joint_pos = Eigen::VectorXd::Zero(joint_positions_.size());
        for (size_t i = 0; i < joint_positions_.size(); i++){
            joint_pos[i] = joint_positions_[i];
        }
        
        Eigen::VectorXd difference = default_joint_position_ - joint_pos;
        if (difference.lpNorm<Eigen::Infinity>() < done_threshold_){
            //checking if any singular entry is larger than the threshold
            done_msg_.data = true;
            done_publisher_->publish(done_msg_);
        }
        else{
            done_msg_.data = false;
            done_publisher_->publish(done_msg_);
        }            

        Eigen::VectorXd x_dot_unscaled = k_att_ * difference;
        Eigen::VectorXd x_dot = x_dot_unscaled;
        //check if any joints are moving too fast:
        for (int i = 0; i < (int)maximum_joint_velocity_.size(); i++){
            if (x_dot_unscaled(i) > maximum_joint_velocity_(i)){
                x_dot(i) = maximum_joint_velocity_(i);
            }
            else if (x_dot_unscaled(i) < -maximum_joint_velocity_(i)){
                x_dot(i) = -maximum_joint_velocity_(i);
            }
        }
        for (int i = 0; i < (int)x_dot.size(); i++){
            joint_velocity_msg_.data[i] = x_dot(i);
        }

        joint_velocity_publisher_->publish(joint_velocity_msg_);
    }
    else{
        // Publish zero velocities when not ready
        for (size_t i = 0; i < joint_velocity_msg_.data.size(); i++){
            joint_velocity_msg_.data[i] = 0.0;
        }
        done_msg_.data = true;
        done_publisher_->publish(done_msg_);
        joint_velocity_publisher_->publish(joint_velocity_msg_);
    }
}

//PRIVATE
void PotentialField2D::sub_callback(const geometry_msgs::msg::PoseArray::SharedPtr msg){
    x_robot_ = msg->poses[5].position.x;
    y_robot_ = msg->poses[5].position.y;
    recieved_first_pose_ = true;
}
//void PotentialField2D::client_callback(const )
// void PotentialField2D::server_callback(const std::shared_ptr<Move2d::Request> request,
//     std::shared_ptr<Move2d::Response> response){
//         //TODO: FILL THIS IN
//         RCLCPP_INFO(this->get_logger(), "Recieved request: x=%f, y=%f", request->x, request->y);
//         x_target_ = request->x;
//         y_target_ = request->y;
//         recieved_first_service_call_ = true;
//         if (!recieved_first_pose_){
//             response->success = false;
//         }
//         else{
//             response->success = true;
//         }
//     }
void PotentialField2D::homing_callback(const std::shared_ptr<Trigger::Request> request, std::shared_ptr<Trigger::Response> response){
    RCLCPP_INFO(this->get_logger(), "Recieved Trigger Request");
    recieved_first_service_call_ = true;
    (void)request;
    if (!recieved_first_pose_){
        response->success = false;
        response->message = "Haven't recieved first pose yet!";
    }
    else{
        response->success =true;
        response->message = "Homing successful";
    }

    
}

void PotentialField2D::joint_callback(const sensor_msgs::msg::JointState::SharedPtr msg){
    //RCLCPP_DEBUG(this->get_logger(), "Recieved Joint State");
    recieved_first_pose_ = true;
    joint_positions_ = msg->position; //float64 array
    //could hypothetically extract name, vel, pos, and effort from the msg
}

//create node




// subscribe to a topic 

// in callback, read the x,y position of the robot using msg.poses and ... save the current position of the robot in a variable
