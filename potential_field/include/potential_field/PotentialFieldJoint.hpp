#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "highlevel_interfaces/srv/move2d.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_srvs/srv/trigger.hpp"
#include <Eigen/Dense>

using Move2d = highlevel_interfaces::srv::Move2d;
using Trigger = std_srvs::srv::Trigger;


class PotentialField2D : public rclcpp::Node {

    public:
        //constructor
        PotentialField2D(const std::string& name);
        //calculate the potential field
        void update();
        //read parameters from ROS
        bool readParameters();
    private:
        //rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr subscriber_; //initialize a private subscriber (use XXX_ to indicate private variable)
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_subscriber_; //joint state subscriber

        //rclcpp::Service<Move2d>::SharedPtr server_; //initialize server
        rclcpp::Service<Trigger>::SharedPtr homing_server_; //homing trigger service

        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr done_publisher_;
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr joint_velocity_publisher_;
        //rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr velocity_publisher_;
        //rclcpp::Client<Move2d>::SharedPtr client_;
        
        void sub_callback(const geometry_msgs::msg::PoseArray::SharedPtr msg);
        void server_callback(const std::shared_ptr<Move2d::Request> request,
                                 std::shared_ptr<Move2d::Response> response);
        void homing_callback(const std::shared_ptr<Trigger::Request> request,
                                std::shared_ptr<Trigger::Response> response);
        void joint_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
        
        bool recieved_first_pose_ = false;
        bool recieved_first_service_call_ = false;
        double x_robot_;
        double y_robot_;
        double x_target_;
        double y_target_;
        std_msgs::msg::Float64MultiArray velocity_msg_;
        std_msgs::msg::Bool done_msg_;

        double v_max_ = 1.0; //m/s
        double eps_ = 0.1; //m
        
        //ASSIGNMENT 3 PARAMS and vars

        std_msgs::msg::Float64MultiArray joint_velocity_msg_;
        double k_att_;

        std::vector<double> default_joint_position_vec_;
        Eigen::VectorXd default_joint_position_; 

        std::vector<double> maximum_joint_velocity_vec_;
        Eigen::VectorXd maximum_joint_velocity_;

        double done_threshold_;

        //Assigment 3 vars
        std::vector<double> joint_positions_; //float64 array size 7



};