
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/multibody/data.hpp"
#include <Eigen/Core>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "highlevel_interfaces/srv/set_kd.hpp"

using SetKD = highlevel_interfaces::srv::SetKD;

class DynamicController : public rclcpp::Node {

    public:
        //constructor
        DynamicController(const std::string& name);
        void calculate_joint_torque();

    private:
        
        //Services
        rclcpp::Service<SetKD>::SharedPtr set_linear_kd_service_;
        rclcpp::Service<SetKD>::SharedPtr set_joint_kd_service_;
        void set_linear_kd_callback(const SetKD::Request::SharedPtr req, SetKD::Response::SharedPtr res);
        void set_joint_kd_callback(const SetKD::Request::SharedPtr req, SetKD::Response::SharedPtr res);


        //SUBSCRIBERS
        //subcribe to robot feedback joint_states
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber_;
        //subscribe to the reference pose/twist
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr reference_twist_subscriber_;
        //subscribe to the reference position
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr reference_joint_position_subscriber_;
        //subscribe to the reference velocity
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr reference_joint_velocity_subscriber_;
        //subscribe to the reference pose
        rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr reference_pose_subscriber_;


        //PUBLISHERS
        //publish the command position:
        //rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr command_position_publisher_;
        //publish gen3/feedback/pose of type /geometry_msgs/msg/Pose
        rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr end_pose_publisher_;
        //publish gen3/feedback/twist of type geometry_msgs/msg/Twist
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr end_twist_publisher_;
        //publish the command torque:
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr joint_torque_publisher_;
        


        //callback functions
        void joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
        void reference_twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg);
        void reference_joint_position_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
        void reference_joint_velocity_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
        void reference_pose_callback(const geometry_msgs::msg::Pose::SharedPtr msg);
        //void reference_homing_velocity_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);

        double linear_k_;
        double linear_d_;
        double joint_k_;
        double joint_d_;

        pinocchio::Model model_;
        pinocchio::Data data_;
        Eigen::MatrixXd M_;
        Eigen::VectorXd h_;
        
        std::string urdf_file_name_;
        Eigen::VectorXd q_;
        Eigen::VectorXd q_ref_;
        Eigen::VectorXd q_dot_;
        Eigen::VectorXd q_dot_ref_;
        Eigen::VectorXd q_ddot_cmd_;

        Eigen::VectorXd x_;
        Eigen::VectorXd x_ref_;
        Eigen::VectorXd x_dot_;
        Eigen::VectorXd x_dot_ref_;
        Eigen::Vector3d x_ddot_cmd_;


        Eigen::VectorXd v_;
        Eigen::VectorXd tau_;
        Eigen::MatrixXd jacobian_;
        Eigen::MatrixXd jacobian_pseudo_;
        Eigen::MatrixXd J_position_;
        Eigen::MatrixXd J_position_pseudo_;
        Eigen::MatrixXd Lambda_;
        Eigen::MatrixXd P_;
        Eigen::MatrixXd Eta_;
        Eigen::VectorXd Tau_task_cmd_;
        Eigen::VectorXd Tau_joint_cmd_;
        Eigen::VectorXd Tau_null_;
        Eigen::VectorXd Tau_cmd_;



        
        bool with_redundancy_;
        Eigen::VectorXd reference_homing_velocity_;
        geometry_msgs::msg::Pose end_pose_msg_;
        geometry_msgs::msg::Twist end_twist_msg_;
        std_msgs::msg::Float64MultiArray joint_vel_command_;
};
