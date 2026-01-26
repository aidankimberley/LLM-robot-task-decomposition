#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "highlevel_interfaces/srv/move2d.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"

using Move2d = highlevel_interfaces::srv::Move2d;


class PotentialField2D : public rclcpp::Node {

    public:
        //constructor
        PotentialField2D(const std::string& name);
        //calculate the potential field
        void update();
    private:
        rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr subscriber_; //initialize a private subscriber (use XXX_ to indicate private variable)
        rclcpp::Service<Move2d>::SharedPtr server_; //initialize server
        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr done_publisher_;
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr velocity_publisher_;
        //rclcpp::Client<Move2d>::SharedPtr client_;
        
        void sub_callback(const geometry_msgs::msg::PoseArray::SharedPtr msg);
        void server_callback(const std::shared_ptr<Move2d::Request> request,
                                std::shared_ptr<Move2d::Response> response);

        
        bool recieved_first_pose_ = false;
        bool recieved_first_service_call_ = false;
        double x_robot_;
        double y_robot_;
        double x_target_;
        double y_target_;
        std_msgs::msg::Float64MultiArray velocity_msg_;
        std_msgs::msg::Bool done_msg_;

        double v_max_ = 1; //m/s
        double k_att_ = 5; //
        double eps_ = 0.1; //m


};