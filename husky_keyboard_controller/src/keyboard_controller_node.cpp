#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include <string>

using Node = rclcpp::Node;
using NodePtr = rclcpp::Node::SharedPtr;
using Subscriber = rclcpp::Subscription<std_msgs::msg::String>::SharedPtr;
using Publisher = rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr;
using Twist = geometry_msgs::msg::TwistStamped;

// Publisher needs to be accessible in callback, so make it global or use lambda
// For simplicity, using a global variable here
Publisher pub = nullptr;

void callback(const std_msgs::msg::String &msg){
    // Access the value from the message using msg.data
    // msg.data is a std::string containing the keyboard character
    std::string value = msg.data;
    // This line checks if the received message is empty.
    // If it's empty, it assigns the null character '\0' to 'cmd'.
    // Otherwise, it assigns the first character of the input string to 'cmd'.
    char cmd = msg.data.empty() ? '\0' : msg.data[0];
    
    // Create a TwistStamped message for cmd_vel
    Twist twist_msg;
    std::string description = "Nothing";
    
    // Set the header timestamp
    // Use rclcpp::Clock to get the current ROS time
    rclcpp::Clock clock;
    twist_msg.header.stamp = clock.now();
    twist_msg.header.frame_id = "base_link";
    
    // Initialize all twist values to zero
    // TwistStamped has a 'twist' field that contains the actual Twist message
    twist_msg.twist.linear.x = 0.0;
    twist_msg.twist.linear.y = 0.0;
    twist_msg.twist.linear.z = 0.0;
    twist_msg.twist.angular.x = 0.0;
    twist_msg.twist.angular.y = 0.0;
    twist_msg.twist.angular.z = 0.0;
    
    // Map keyboard commands to twist velocities
    if (cmd == 'i'){
        twist_msg.twist.linear.x = 0.5;
        description = "Forward";
    }
    if (cmd == 'u'){
        twist_msg.twist.linear.x = 0.5;
        twist_msg.twist.angular.z = 0.5;
        description = "Left";
    }
    if (cmd == 'o'){
        twist_msg.twist.linear.x = 0.5;
        twist_msg.twist.angular.z = -0.5;
        description = "Right";
    }
    
    // Publish the twist command
    if (pub) {
        pub->publish(twist_msg);
        RCLCPP_INFO(rclcpp::get_logger("keyboard_controller_node"), "Received: '%s', publishing cmd_vel: '%s'", value.c_str(), description.c_str());
    }
}

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    NodePtr node = std::make_shared<Node>("keyboard_controller_node");
    Subscriber sub = node->create_subscription<std_msgs::msg::String>("/keyboard_reader/cmd", 1, callback);
    pub = node->create_publisher<Twist>("/husky/cmd_vel", 5);
    rclcpp::Rate loop_rate(100);

    while (rclcpp::ok()){
        // Process callbacks 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    
    rclcpp::shutdown();
    return 0;
}
