
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/multibody/data.hpp"
#include "pinocchio/multibody/fwd.hpp"
#include <Eigen/Core>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"

class KinematicController : public rclcpp::Node {

    public:
        //constructor
        KinematicController(const std::string& name);
        void SendCommands();

    private:

        //SUBSCRIBERS
        //subcribe to robot feedback joint_states
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber_;
        //subscribe to the reference pose/twist
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr reference_twist_subscriber_;
        //subscribe to the reference velocity
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr reference_homing_velocity_subscriber_;
        //PUBLISHERS
        //publish the command position:
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr command_position_publisher_;
        //publish gen3/feedback/pose of type /geometry_msgs/msg/Pose
        rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr end_pose_publisher_;
        //publish gen3/feedback/twist of type geometry_msgs/msg/Twist
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr end_twist_publisher_;
        
        //callback functions
        void joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
        void reference_twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg);
        void reference_homing_velocity_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);

        pinocchio::Model model_;
        pinocchio::Data data_;
        std::string urdf_file_name_;
        Eigen::VectorXd q_;
        Eigen::VectorXd v_;
        Eigen::VectorXd tau_;
        Eigen::MatrixXd jacobian_;
        Eigen::MatrixXd jacobian_pos_;
        
        bool with_redundancy_;
        bool use_6D_;
        pinocchio::FrameIndex ee_frame_id_;
        Eigen::VectorXd reference_homing_velocity_;
        geometry_msgs::msg::Pose end_pose_;
        geometry_msgs::msg::Twist end_twist_;
        std_msgs::msg::Float64MultiArray joint_vel_command_;
};
