#include "rclcpp/rclcpp.hpp"
#include "dynamic_controller/DynamicController.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/rnea.hpp"
#include "pinocchio/algorithm/compute-all-terms.hpp"
#include <Eigen/Geometry>
#include <functional>

using std::placeholders::_1;
using SetKD = highlevel_interfaces::srv::SetKD;

DynamicController::DynamicController(const std::string& name) : rclcpp::Node(name){
    
    //read in parameters (urdf file name)
    this->declare_parameter<double>("linear_k", 100.0);
    this->declare_parameter<double>("linear_d", 10.0);
    this->declare_parameter<double>("joint_k", 100.0);
    this->declare_parameter<double>("joint_d", 10.0);
    this->declare_parameter<bool>("with_redundancy", false);

    this->declare_parameter<std::string>("urdf_file_name", "");
    this->declare_parameter<std::string>("joint_state_topic", "");
    this->declare_parameter<std::string>("end_pose_topic", "");
    this->declare_parameter<std::string>("end_twist_topic", "");
    this->declare_parameter<std::string>("joint_velocity_command_topic", "");
    this->declare_parameter<std::string>("reference_twist_topic", "");
    this->declare_parameter<std::string>("reference_homing_velocity_topic", "");
    auto joint_state_topic = this->get_parameter("joint_state_topic").as_string();
    auto end_pose_topic = this->get_parameter("end_pose_topic").as_string();
    auto end_twist_topic = this->get_parameter("end_twist_topic").as_string();
    auto joint_velocity_command_topic = this->get_parameter("joint_velocity_command_topic").as_string();
    auto reference_twist_topic = this->get_parameter("reference_twist_topic").as_string();
    auto reference_homing_velocity_topic = this->get_parameter("reference_homing_velocity_topic").as_string();
    with_redundancy_ = this->get_parameter("with_redundancy").as_bool();
    linear_k_ = this->get_parameter("linear_k").as_double();
    linear_d_ = this->get_parameter("linear_d").as_double();
    joint_k_ = this->get_parameter("joint_k").as_double();
    joint_d_ = this->get_parameter("joint_d").as_double();

    if (!this->get_parameter("urdf_file_name", urdf_file_name_)){
        RCLCPP_WARN(this->get_logger(), "Failed to get parameter urdf_file_name, setting to default value");
    }
    else{
        this->urdf_file_name_ = this->get_parameter("urdf_file_name").as_string();
        RCLCPP_INFO(this->get_logger(), "urdf_file_name: %s", urdf_file_name_.c_str());
    }

    joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>(joint_state_topic, 10, 
        std::bind(&DynamicController::joint_state_callback, this, _1));
    reference_joint_position_subscriber_ = this->create_subscription<std_msgs::msg::Float64MultiArray>("/gen3/reference/position", 10,
        std::bind(&DynamicController::reference_joint_position_callback, this, _1));
    reference_joint_velocity_subscriber_ = this->create_subscription<std_msgs::msg::Float64MultiArray>("/gen3/reference/velocity", 10,
        std::bind(&DynamicController::reference_joint_velocity_callback, this, _1));
    reference_pose_subscriber_ = this->create_subscription<geometry_msgs::msg::Pose>("/gen3/reference/pose", 10,
        std::bind(&DynamicController::reference_pose_callback, this, _1));
    reference_twist_subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>(reference_twist_topic,10,
        std::bind(&DynamicController::reference_twist_callback, this, _1));
    // reference_homing_velocity_subscriber_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(reference_homing_velocity_topic, 10,
    //     std::bind(&KinematicController::reference_homing_velocity_callback, this, _1));
    

    end_pose_publisher_ = this->create_publisher<geometry_msgs::msg::Pose>(end_pose_topic, 10);
    end_twist_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(end_twist_topic, 10);
    //command_position_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(joint_velocity_command_topic, 10);
    joint_torque_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/joint_effort_controller/commands", 10);

    //Services
    set_linear_kd_service_ = this->create_service<SetKD>("/gen3/set_linear_kd", std::bind(&DynamicController::set_linear_kd_callback, this, 
        std::placeholders::_1, std::placeholders::_2));
    set_joint_kd_service_ = this->create_service<SetKD>("/gen3/set_joint_kd", std::bind(&DynamicController::set_joint_kd_callback, this,
        std::placeholders::_1, std::placeholders::_2));

    

    //load the model
    pinocchio::urdf::buildModel(urdf_file_name_, model_, false);//set true to display details
    data_ = pinocchio::Data(model_);
    q_ = Eigen::VectorXd::Zero(model_.nq);
    q_dot_ = Eigen::VectorXd::Zero(model_.nv);
    reference_homing_velocity_ = Eigen::VectorXd::Zero(model_.nv);
    jacobian_ = Eigen::MatrixXd::Zero(6, model_.nv);
    J_position_ = Eigen::MatrixXd::Zero(3, model_.nv);
    jacobian_pseudo_ = Eigen::MatrixXd::Zero(model_.nv, 6);
    J_position_pseudo_ = Eigen::MatrixXd::Zero(3, model_.nv);
    Lambda_ = Eigen::MatrixXd::Zero(model_.nv, model_.nv);
    Eta_ = Eigen::MatrixXd::Zero(model_.nv, model_.nv);
    Tau_cmd_ = Eigen::VectorXd::Zero(model_.nv);
    M_ = Eigen::MatrixXd::Zero(model_.nv, model_.nv);
    h_ = Eigen::VectorXd::Zero(model_.nv);
    x_ = Eigen::Vector3d::Zero();
    x_ref_ = Eigen::Vector3d::Zero();
    x_dot_ = Eigen::Vector3d::Zero();
    x_dot_ref_ = Eigen::Vector3d::Zero();

    RCLCPP_INFO(this->get_logger(), "dq size: %d", model_.nq);
    RCLCPP_INFO(this->get_logger(), "dv size: %d", model_.nv);
}


void DynamicController::calculate_joint_torque(){
    x_ddot_cmd_ = linear_d_ * Eigen::Matrix3d::Identity() *(x_dot_ref_ - x_dot_) + linear_k_ * Eigen::Matrix3d::Identity() * (x_ref_ - x_);
    auto HAND_ID = model_.getJointId("end-effector_link") - 1;
    
    pinocchio::computeAllTerms(model_, data_, q_, q_dot_);
    pinocchio::getJointJacobian(model_, data_, HAND_ID, pinocchio::ReferenceFrame::LOCAL_WORLD_ALIGNED, jacobian_);
    jacobian_pseudo_ = jacobian_.completeOrthogonalDecomposition().pseudoInverse();
    J_position_ = jacobian_.topRows(3);
    J_position_pseudo_ = jacobian_pseudo_.leftCols(3);
    //pinocchio::crba(model_, data_, q_);
    M_ = data_.M;
    h_ = data_.nle;
    Eigen::Vector3d a_ = data_.a[HAND_ID].linear();

    Lambda_ = J_position_pseudo_.transpose() * M_ * J_position_pseudo_ ; //3x7 @ 7x7 @ 7x3 = 3x3
    //Lambda_ = (J_position_pseudo_ * M_.inverse() * J_position_.transpose()).inverse(); //7x3 @ 7x7 @ 3x7 = 
    Eta_ = J_position_pseudo_.transpose() * h_ - Lambda_ * a_;
    Tau_cmd_ = J_position_.transpose() * (Lambda_ * x_ddot_cmd_ + Eta_);
    std_msgs::msg::Float64MultiArray torque_msg;
    torque_msg.data.resize(model_.nv);
    for (int i = 0; i < model_.nv; i++){
        torque_msg.data[i] = Tau_cmd_[i];
    }
    joint_torque_publisher_->publish(torque_msg);
}



void DynamicController::set_linear_kd_callback(const SetKD::Request::SharedPtr req, SetKD::Response::SharedPtr res){
    linear_k_ = req->k;
    linear_d_ = req->d;
    res->success = true;
    RCLCPP_INFO(this->get_logger(), "Linear K: %f, Linear D: %f", linear_k_, linear_d_);
}

void DynamicController::set_joint_kd_callback(const SetKD::Request::SharedPtr req, SetKD::Response::SharedPtr res){
    joint_k_ = req->k;
    joint_d_ = req->d;
    res->success = true;
}

void DynamicController::reference_joint_position_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
    q_ref_ = Eigen::Map<const Eigen::VectorXd>(msg->data.data(), msg->data.size());
}

void DynamicController::reference_joint_velocity_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
    q_dot_ref_ = Eigen::Map<const Eigen::VectorXd>(msg->data.data(), msg->data.size());
}

void DynamicController::reference_pose_callback(const geometry_msgs::msg::Pose::SharedPtr msg){
    x_ref_ = Eigen::Vector3d(msg->position.x, msg->position.y, msg->position.z);
}
void DynamicController::reference_twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg){
    x_dot_ref_ = Eigen::Vector3d(msg->linear.x, msg->linear.y, msg->linear.z);
}




void DynamicController::joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg){
    //Forward Kinematics
    // Convert std::vector to Eigen::VectorXd
    RCLCPP_DEBUG(this->get_logger(), "Joint state callback received");
    q_ = Eigen::Map<const Eigen::VectorXd>(msg->position.data(), model_.nq);
    q_dot_ = Eigen::Map<const Eigen::VectorXd>(msg->velocity.data(), model_.nv);

    //calculate the end effector pose and twist
    pinocchio::forwardKinematics(model_, data_, q_, q_dot_);
    pinocchio::computeJointJacobians(model_, data_, q_);
    
    auto HAND_ID = model_.getJointId("end-effector_link") - 1;

    pinocchio::SE3 fbk_pose = data_.oMi[HAND_ID];

    x_ = fbk_pose.translation(); //eigen vector
    Eigen::Matrix3d fbk_rot = fbk_pose.rotation(); //rotation matrix
    //get quaternion from rotation matrix
    Eigen::Quaterniond quat(fbk_rot); //quaternion form -> need for pose msg

    jacobian_ = Eigen::MatrixXd::Zero(6, model_.nv);
    pinocchio::getJointJacobian(model_, data_, HAND_ID, pinocchio::ReferenceFrame::LOCAL_WORLD_ALIGNED, jacobian_);

    Eigen::VectorXd twist_vector = jacobian_ * q_dot_; //6x1
    x_dot_ = twist_vector.head<3>();

    //need to publish pose and twist
    end_pose_msg_.position.x = x_[0];
    end_pose_msg_.position.y = x_[1];
    end_pose_msg_.position.z = x_[2];
    end_pose_msg_.orientation.x = quat.x();
    end_pose_msg_.orientation.y = quat.y();
    end_pose_msg_.orientation.z = quat.z();
    end_pose_msg_.orientation.w = quat.w();

    RCLCPP_DEBUG(this->get_logger(), "End effector pose: %f, %f, %f", end_pose_msg_.position.x, end_pose_msg_.position.y, end_pose_msg_.position.z);
    RCLCPP_DEBUG(this->get_logger(), "End effector orientation: %f, %f, %f, %f", end_pose_msg_.orientation.x, end_pose_msg_.orientation.y, end_pose_msg_.orientation.z, end_pose_msg_.orientation.w);

    end_twist_msg_.linear.x = twist_vector[0];
    end_twist_msg_.linear.y = twist_vector[1];
    end_twist_msg_.linear.z = twist_vector[2];
    end_twist_msg_.angular.x = twist_vector[3];
    end_twist_msg_.angular.y = twist_vector[4];
    end_twist_msg_.angular.z = twist_vector[5];

    //Keep these publishers
    end_pose_publisher_->publish(end_pose_msg_);
    end_twist_publisher_->publish(end_twist_msg_);

    // RCLCPP_DEBUG(this->get_logger(), "End effector pose: %f, %f, %f", end_pose_.position.x, end_pose_.position.y, end_pose_.position.z);
    // RCLCPP_DEBUG(this->get_logger(), "End effector twist: %f, %f, %f", end_twist_.linear.x, end_twist_.linear.y, end_twist_.linear.z);
    // RCLCPP_DEBUG(this->get_logger(), "End effector twist: %f, %f, %f", end_twist_.angular.x, end_twist_.angular.y, end_twist_.angular.z);
}

// void KinematicController::reference_homing_velocity_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
//     RCLCPP_DEBUG(this->get_logger(), "Reference homing velocity callback received");
//     const std::vector<double>& data = msg->data;
//     reference_homing_velocity_ = Eigen::VectorXd::Zero(data.size());
//     for (size_t i = 0; i < data.size(); i++){
//         reference_homing_velocity_(i) = data[i];
//     }
// }

// void DynamicController::reference_twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg){
//     RCLCPP_DEBUG(this->get_logger(), "IK callback received");
//     //inverse kinematics
//     //q_dot = J_pseudo * x_dot

//     //POTNEITALLY ONLY NEED TO CALCULATE THE  XYZ TRANSLATION -> JACOBIAN ONLY TOP 3 ROWS
    
//     // Use full 6D twist (linear + angular)
//     Eigen::VectorXd x_dot(6);
//     x_dot(0) = msg->linear.x;
//     x_dot(1) = msg->linear.y;
//     x_dot(2) = msg->linear.z;
//     x_dot(3) = msg->angular.x;
//     x_dot(4) = msg->angular.y;
//     x_dot(5) = msg->angular.z;

//     // jacobian_ is 6 x nv, pseudoInverse is nv x 6, x_dot is 6 x 1 -> q_dot is nv x 1
//     Eigen::MatrixXd jacobian_pseudo = jacobian_.completeOrthogonalDecomposition().pseudoInverse();
//     Eigen::VectorXd q_dot;
//     if (with_redundancy_){
//         Eigen::MatrixXd N = Eigen::MatrixXd::Identity(model_.nv, model_.nv) - jacobian_pseudo * jacobian_;
//         q_dot = jacobian_pseudo * x_dot + N * reference_homing_velocity_;
//     }
//     else{
//         q_dot = jacobian_pseudo * x_dot;
//     }
    
//     //convert to std::vector
//     std::vector<double> q_dot_vector(q_dot.size());
//     for (Eigen::Index i = 0; i < q_dot.size(); i++){
//         q_dot_vector[i] = q_dot(i);
//     }

//     joint_vel_command_.data = q_dot_vector;
//     RCLCPP_DEBUG(this->get_logger(), "Publishing command vel: %f, %f, %f", q_dot_vector[0], q_dot_vector[1], q_dot_vector[2]);
//     command_position_publisher_->publish(joint_vel_command_);
// }

// void DynamicController::reference_