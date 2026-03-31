#include "rclcpp/rclcpp.hpp"
#include "kinematic_controller/KinematicController.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/frames.hpp"
#include "pinocchio/algorithm/rnea.hpp"
#include <Eigen/Geometry>
#include <functional>

using std::placeholders::_1;

KinematicController::KinematicController(const std::string& name) : rclcpp::Node(name){
    
    //read in parameters (urdf file name)
    this->declare_parameter<std::string>("urdf_file_name", "");
    this->declare_parameter<std::string>("joint_state_topic", "");
    this->declare_parameter<std::string>("end_pose_topic", "");
    this->declare_parameter<std::string>("end_twist_topic", "");
    this->declare_parameter<std::string>("joint_velocity_command_topic", "");
    this->declare_parameter<std::string>("reference_twist_topic", "");
    this->declare_parameter<std::string>("reference_homing_velocity_topic", "");
    this->declare_parameter<bool>("with_redundancy", false);
    this->declare_parameter<bool>("use_6D",false);
    auto joint_state_topic = this->get_parameter("joint_state_topic").as_string();
    auto end_pose_topic = this->get_parameter("end_pose_topic").as_string();
    auto end_twist_topic = this->get_parameter("end_twist_topic").as_string();
    auto joint_velocity_command_topic = this->get_parameter("joint_velocity_command_topic").as_string();
    auto reference_twist_topic = this->get_parameter("reference_twist_topic").as_string();
    auto reference_homing_velocity_topic = this->get_parameter("reference_homing_velocity_topic").as_string();
    with_redundancy_ = this->get_parameter("with_redundancy").as_bool();
    use_6D_ = this->get_parameter("use_6D").as_bool();
    if (!this->get_parameter("urdf_file_name", urdf_file_name_)){
        RCLCPP_WARN(this->get_logger(), "Failed to get parameter urdf_file_name, setting to default value");
    }
    else{
        this->urdf_file_name_ = this->get_parameter("urdf_file_name").as_string();
        RCLCPP_INFO(this->get_logger(), "urdf_file_name: %s", urdf_file_name_.c_str());
    }
    joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>(joint_state_topic, 10, 
        std::bind(&KinematicController::joint_state_callback, this, _1));
    reference_twist_subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>(reference_twist_topic,10,
        std::bind(&KinematicController::reference_twist_callback, this, _1));
    reference_homing_velocity_subscriber_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(reference_homing_velocity_topic, 10,
        std::bind(&KinematicController::reference_homing_velocity_callback, this, _1));

    end_pose_publisher_ = this->create_publisher<geometry_msgs::msg::Pose>(end_pose_topic, 10);
    end_twist_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(end_twist_topic, 10);
    command_position_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(joint_velocity_command_topic, 10);
    
    //load the model
    pinocchio::urdf::buildModel(urdf_file_name_, model_, false);//set true to display details
    data_ = pinocchio::Data(model_);
    q_ = Eigen::VectorXd::Zero(model_.nq);
    v_ = Eigen::VectorXd::Zero(model_.nv);
    reference_homing_velocity_ = Eigen::VectorXd::Zero(model_.nv);
    jacobian_ = Eigen::MatrixXd::Zero(6, model_.nv);
    ee_frame_id_ = model_.getFrameId("end_effector_link");
}

void KinematicController::joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg){
    RCLCPP_DEBUG(this->get_logger(), "Joint state callback received");
    if (static_cast<Eigen::Index>(msg->position.size()) != model_.nq ||
        static_cast<Eigen::Index>(msg->velocity.size()) != model_.nv) {
        RCLCPP_WARN_THROTTLE(
            this->get_logger(), *this->get_clock(), 2000,
            "JointState size mismatch: position %zu velocity %zu (expected nq=%d nv=%d). "
            "Use a URDF whose controlled DOF match /joint_states.",
            msg->position.size(), msg->velocity.size(), static_cast<int>(model_.nq),
            static_cast<int>(model_.nv));
        return;
    }
    q_ = Eigen::Map<const Eigen::VectorXd>(msg->position.data(), model_.nq);
    v_ = Eigen::Map<const Eigen::VectorXd>(msg->velocity.data(), model_.nv);

    pinocchio::forwardKinematics(model_, data_, q_, v_);
    pinocchio::computeJointJacobians(model_, data_, q_);
    pinocchio::updateFramePlacements(model_, data_);

    const pinocchio::SE3& fbk_pose = data_.oMf[ee_frame_id_];
    Eigen::Vector3d fbk_pos = fbk_pose.translation();
    Eigen::Matrix3d fbk_rot = fbk_pose.rotation();
    Eigen::Quaterniond quat(fbk_rot);

    pinocchio::getFrameJacobian(model_, data_, ee_frame_id_,
                                pinocchio::ReferenceFrame::LOCAL_WORLD_ALIGNED, jacobian_);

    Eigen::VectorXd twist_vector = jacobian_ * v_;

    //need to publish pose and twist
    end_pose_.position.x = fbk_pos[0];
    end_pose_.position.y = fbk_pos[1];
    end_pose_.position.z = fbk_pos[2];
    end_pose_.orientation.x = quat.x();
    end_pose_.orientation.y = quat.y();
    end_pose_.orientation.z = quat.z();
    end_pose_.orientation.w = quat.w();

    RCLCPP_DEBUG(this->get_logger(), "End effector pose: %f, %f, %f", end_pose_.position.x, end_pose_.position.y, end_pose_.position.z);
    RCLCPP_DEBUG(this->get_logger(), "End effector orientation: %f, %f, %f, %f", end_pose_.orientation.x, end_pose_.orientation.y, end_pose_.orientation.z, end_pose_.orientation.w);

    end_twist_.linear.x = twist_vector[0];
    end_twist_.linear.y = twist_vector[1];
    end_twist_.linear.z = twist_vector[2];
    end_twist_.angular.x = twist_vector[3];
    end_twist_.angular.y = twist_vector[4];
    end_twist_.angular.z = twist_vector[5];

    end_pose_publisher_->publish(end_pose_);
    end_twist_publisher_->publish(end_twist_);

    // RCLCPP_DEBUG(this->get_logger(), "End effector pose: %f, %f, %f", end_pose_.position.x, end_pose_.position.y, end_pose_.position.z);
    // RCLCPP_DEBUG(this->get_logger(), "End effector twist: %f, %f, %f", end_twist_.linear.x, end_twist_.linear.y, end_twist_.linear.z);
    // RCLCPP_DEBUG(this->get_logger(), "End effector twist: %f, %f, %f", end_twist_.angular.x, end_twist_.angular.y, end_twist_.angular.z);
}

void KinematicController::reference_homing_velocity_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
    RCLCPP_DEBUG(this->get_logger(), "Reference homing velocity callback received");
    reference_homing_velocity_.setZero();
    const std::vector<double>& data = msg->data;
    const Eigen::Index n =
        std::min(static_cast<Eigen::Index>(data.size()), static_cast<Eigen::Index>(model_.nv));
    for (Eigen::Index i = 0; i < n; ++i) {
        reference_homing_velocity_(i) = data[static_cast<size_t>(i)];
    }
}

void KinematicController::reference_twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg){
    RCLCPP_DEBUG(this->get_logger(), "IK callback received");

    Eigen::VectorXd q_dot(model_.nv);
    if (use_6D_) {
        Eigen::VectorXd x_dot(6);
        x_dot << msg->linear.x, msg->linear.y, msg->linear.z, msg->angular.x, msg->angular.y,
            msg->angular.z;
        const Eigen::MatrixXd jacobian_pseudo =
            jacobian_.completeOrthogonalDecomposition().pseudoInverse();
        if (with_redundancy_) {
            const Eigen::MatrixXd N =
                Eigen::MatrixXd::Identity(model_.nv, model_.nv) - jacobian_pseudo * jacobian_;
            q_dot = jacobian_pseudo * x_dot + N * reference_homing_velocity_;
        } else {
            q_dot = jacobian_pseudo * x_dot;
        }
    } else {
        Eigen::VectorXd x_dot(3);
        x_dot << msg->linear.x, msg->linear.y, msg->linear.z;
        jacobian_pos_ = jacobian_.topRows(3);
        const Eigen::MatrixXd jacobian_pos_pseudo =
            jacobian_pos_.completeOrthogonalDecomposition().pseudoInverse();
        if (with_redundancy_) {
            const Eigen::MatrixXd N =
                Eigen::MatrixXd::Identity(model_.nv, model_.nv) - jacobian_pos_pseudo * jacobian_pos_;
            q_dot = jacobian_pos_pseudo * x_dot + N * reference_homing_velocity_;
        } else {
            q_dot = jacobian_pos_pseudo * x_dot;
        }
    }

    //convert to std::vector
    std::vector<double> q_dot_vector(q_dot.size());
    for (Eigen::Index i = 0; i < q_dot.size(); i++){
        q_dot_vector[i] = q_dot(i);
    }

    joint_vel_command_.data = q_dot_vector;
    RCLCPP_DEBUG(this->get_logger(), "Publishing command vel: %f, %f, %f", q_dot_vector[0], q_dot_vector[1], q_dot_vector[2]);
    command_position_publisher_->publish(joint_vel_command_);
}