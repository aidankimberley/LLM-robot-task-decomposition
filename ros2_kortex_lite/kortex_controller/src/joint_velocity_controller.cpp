#include <string>
#include <Eigen/Dense>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/logger.hpp>

#include <std_msgs/msg/float64_multi_array.hpp>
#include <sensor_msgs/msg/joint_state.hpp>


class JointVelocityController : public rclcpp::Node { 

    public: 
    
    JointVelocityController(): rclcpp::Node("joint_velocity_controller", rclcpp::NodeOptions().allow_undeclared_parameters(true)) {

        cmd_joint_pos_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>
            (cmd_joint_pos_topic_name_, 1);

        des_joint_vel_subscriber_ = this->create_subscription<std_msgs::msg::Float64MultiArray>
            (des_joint_vel_topic_name_, 1, 
            std::bind(&JointVelocityController::des_joint_vel_callback, this, std::placeholders::_1));
            
        fbk_joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>
            (fbk_joint_state_topic_name_, 1, 
                std::bind(&JointVelocityController::fbk_joint_state_callback, this, std::placeholders::_1));


        // this->declare_parameter("k_att", 5.0);

        // std::vector<double> default_joint_positions ;
        // default_joint_positions.push_back(0.0) ;
        // default_joint_positions.push_back(0.5) ;
        // default_joint_positions.push_back(0.0) ;
        // default_joint_positions.push_back(0.5) ;
        // default_joint_positions.push_back(0.0) ;
        // default_joint_positions.push_back(0.6) ;
        // default_joint_positions.push_back(0.0) ;

        // std::vector<double> maximum_joint_velocities ;
        // maximum_joint_velocities.push_back(1.0) ;
        // maximum_joint_velocities.push_back(1.0) ;
        // maximum_joint_velocities.push_back(1.0) ;
        // maximum_joint_velocities.push_back(1.0) ;
        // maximum_joint_velocities.push_back(1.0) ;
        // maximum_joint_velocities.push_back(1.0) ;
        // maximum_joint_velocities.push_back(1.0) ;
        // this->declare_parameter("default_joint_position", default_joint_positions) ;
        // this->declare_parameter("maximum_joint_velocity", maximum_joint_velocities) ;

        cmd_joint_pos_ = Eigen::VectorXd::Zero(dim_joints);
        fbk_joint_pos_ = Eigen::VectorXd::Zero(dim_joints);
        des_joint_vel_ = Eigen::VectorXd::Zero(dim_joints);   
                    
        cmd_joint_pos_msg_.data.push_back(0.0) ;
        cmd_joint_pos_msg_.data.push_back(0.0) ;
        cmd_joint_pos_msg_.data.push_back(0.0) ;
        cmd_joint_pos_msg_.data.push_back(0.0) ;
        cmd_joint_pos_msg_.data.push_back(0.0) ;
        cmd_joint_pos_msg_.data.push_back(0.0) ;
        cmd_joint_pos_msg_.data.push_back(0.0) ;
    }

    void des_joint_vel_callback(const std_msgs::msg::Float64MultiArray& msg) {
        
        
        des_joint_vel_ready_ = true ;
        for ( int i = 0 ; i < dim_joints ; i++ ) {
            des_joint_vel_(i) = msg.data[i] ;
        }
        
        RCLCPP_DEBUG_ONCE(this->get_logger(), "received des_joint_vel_callback") ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "des_joint_vel_(0) %f", des_joint_vel_(0) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "des_joint_vel_(1) %f", des_joint_vel_(1) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "des_joint_vel_(2) %f", des_joint_vel_(2) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "des_joint_vel_(3) %f", des_joint_vel_(3) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "des_joint_vel_(4) %f", des_joint_vel_(4) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "des_joint_vel_(5) %f", des_joint_vel_(5) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "des_joint_vel_(6) %f", des_joint_vel_(6) ) ;
    }

    void fbk_joint_state_callback(const sensor_msgs::msg::JointState& msg) {    
        
        fbk_joint_state_ready_ = true ;
        for ( int i = 0 ; i < dim_joints ; i++ ) {
            fbk_joint_pos_(i) = msg.position[i] ;
        }

        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_state_callback") ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_pos_(0) %f", fbk_joint_pos_(0) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_pos_(1) %f", fbk_joint_pos_(1) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_pos_(2) %f", fbk_joint_pos_(2) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_pos_(3) %f", fbk_joint_pos_(3) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_pos_(4) %f", fbk_joint_pos_(4) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_pos_(5) %f", fbk_joint_pos_(5) ) ;
        RCLCPP_DEBUG_ONCE(this->get_logger(), "fbk_joint_pos_(6) %f", fbk_joint_pos_(6) ) ;
    }

    bool isReady() {
        return des_joint_vel_ready_ && fbk_joint_state_ready_ ;
    }

    void update() {
        cmd_joint_pos_ = fbk_joint_pos_ + des_joint_vel_ * dt_ * 5 ;
        for ( int i = 0 ; i < dim_joints ; i++ ) {
            cmd_joint_pos_msg_.data[i] = cmd_joint_pos_(i) ;
        }
        cmd_joint_pos_publisher_-> publish(cmd_joint_pos_msg_) ;
    }

    private:
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr      cmd_joint_pos_publisher_ ;
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr   des_joint_vel_subscriber_ ;
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr       fbk_joint_state_subscriber_ ;

        std_msgs::msg::Float64MultiArray cmd_joint_pos_msg_ ;

        std::string cmd_joint_pos_topic_name_ = "/joint_position_controller/commands" ;
        //std::string des_joint_vel_topic_name_ = "/planner/joint_velocity" ; // a3
        std::string des_joint_vel_topic_name_ = "/gen3/command/joint_velocity";
        std::string fbk_joint_state_topic_name_ = "/joint_states";
        
        Eigen::VectorXd fbk_joint_pos_ ;
        Eigen::VectorXd des_joint_vel_ ;
        Eigen::VectorXd cmd_joint_pos_ ;

        double dt_  = 0.002 ;
        int dim_joints = 7 ;

        bool fbk_joint_state_ready_ = false ;
        bool des_joint_vel_ready_ = false ;
};


int main(int argc, char **argv) {

    rclcpp::init(argc, argv);
   
    std::shared_ptr<JointVelocityController> node_handle = std::make_shared<JointVelocityController>();

    RCLCPP_INFO_STREAM(node_handle->get_logger(), "start joint_velocity_controller" );

    rclcpp::Rate loop_rate(500);



    while ( rclcpp::ok() ){
      
        // update
        if ( node_handle-> isReady() ) {
            node_handle-> update() ;
        }

        // call all the callbacks waiting to be called 
        rclcpp::spin_some(node_handle);

        // sleep for any time remaining to the publish rate
        loop_rate.sleep();       
    }

    RCLCPP_INFO_STREAM(node_handle->get_logger(), "joint_velocity_controller is down" );
    rclcpp::shutdown();
    return 0 ;
}