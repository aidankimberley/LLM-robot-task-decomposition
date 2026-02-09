#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "highlevel_interfaces/srv/move3d.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"

using Move3d = highlevel_interfaces::srv::Move3d;


class PotentialFieldTask : public rclcpp::Node {

    public:
        //constructor
        PotentialFieldTask(const std::string& name);
        //calculate the potential field
        void update();
    private:
        rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr subscriber_; //initialize a private subscriber
        rclcpp::Service<Move3d>::SharedPtr server_; //initialize server
        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr done_publisher_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
        
        void sub_callback(const geometry_msgs::msg::Pose::SharedPtr msg);
        void server_callback(const std::shared_ptr<Move3d::Request> request,
                                std::shared_ptr<Move3d::Response> response);

        int publish_rate_;
        bool recieved_first_pose_ = false;
        bool recieved_first_service_call_ = false;
        double x_robot_;
        double y_robot_;
        double z_robot_;
        double x_target_;
        double y_target_;
        double z_target_;
        geometry_msgs::msg::Twist velocity_msg_;
        std_msgs::msg::Bool done_msg_;

        double v_max_; //m/s
        double k_att_; //
        double eps_; //m


};