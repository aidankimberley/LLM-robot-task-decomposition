#include <rclcpp/rclcpp.hpp> // include ROS2 
#include <std_msgs/msg/string.hpp>

class HelloTopicPublisher { 

    public: 
        // Constructor: called when an instance is generated
        HelloTopicPublisher(const rclcpp::Node::SharedPtr &node);
        // Any functions that you want to write
        void update();

    private: 
        rclcpp::Node::SharedPtr node_;  // ROS2 node
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; // make a publisher

        int counter_ = 0;
        std_msgs::msg::String message_;
}; 


