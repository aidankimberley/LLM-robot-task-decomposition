#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <controller_manager_msgs/srv/configure_controller.hpp>
#include <controller_manager_msgs/srv/list_controllers.hpp>
#include <controller_manager_msgs/srv/load_controller.hpp>
#include <controller_manager_msgs/srv/switch_controller.hpp>
#include <ros_gz_interfaces/srv/control_world.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
using namespace std::chrono_literals;

class GazeboSpawnerManager : public rclcpp::Node {



public:
    GazeboSpawnerManager() : Node("gazebo_spawner_manager") {

        // Initialize Clients
        config_client_  = this->create_client<controller_manager_msgs::srv::ConfigureController>("/controller_manager/configure_controller");
        list_client_    = this->create_client<controller_manager_msgs::srv::ListControllers>("/controller_manager/list_controllers");
        load_client_    = this->create_client<controller_manager_msgs::srv::LoadController>("/controller_manager/load_controller");
        switch_client_  = this->create_client<controller_manager_msgs::srv::SwitchController>("/controller_manager/switch_controller");
        gz_client_      = this->create_client<ros_gz_interfaces::srv::ControlWorld>("/world/empty/control");

        gz_request_     = std::make_shared<ros_gz_interfaces::srv::ControlWorld::Request>();

        fake_joint_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("/joint_states", 1);

        for ( int i = 0 ; i < 7 ; i++ ) {
            fake_joint_msg_.name.push_back("Joint_"+i) ;
            fake_joint_msg_.position.push_back(0.0) ;
            fake_joint_msg_.velocity.push_back(0.0) ;
            fake_joint_msg_.effort.push_back(0.0) ;
        }
        fake_joint_msg_.position[1] = 0.6 ;
        fake_joint_msg_.position[3] = 0.6 ;
        fake_joint_msg_.position[5] = 0.6 ;
    }



    void run() {

        // 1. Wait for services to become available
        while ( !gz_client_->wait_for_service(5s) || !list_client_->wait_for_service(5s) || !load_client_-> wait_for_service(5s) ) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "\n\n rclcpp returns false \n\n");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Waiting for Gazebo/Controller Manager services...");
        }

        // 2. Load Controllers
        RCLCPP_INFO(this->get_logger(), "Loading joint_state_broadcaster...");
        send_load_request("joint_state_broadcaster");

        RCLCPP_INFO(this->get_logger(), "Loading joint_effort_controller...");
        send_load_request("joint_effort_controller");
        

        // make sure configure service is ready
        while ( !config_client_-> wait_for_service(5s) ) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "rclcpp returns false");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Waiting for controller_manager/configure_controller services...");
        }

        
        bool configure_ready_ = false ;
        int counter = 0 ;
        while ( !configure_ready_ && counter < 10 ) {
            
            RCLCPP_INFO(this->get_logger(), "Stepping Gazebo");
            step_gazebo(1);

            // try to configure. If it failed, wait
            configure_ready_ = send_configure_request() ;           
            
            rclcpp::spin_some(this->get_node_base_interface());
            rclcpp::sleep_for(10ms); 
            counter++ ;            
        }
        
        // publish a fake joint-state, before gazebo, to reduce the delay
        fake_joint_publisher_-> publish(fake_joint_msg_);

        // done, pause gazebo
        pause_gazebo() ;


        // 3. Activate Controllers
        RCLCPP_INFO(this->get_logger(), "Activating controllers...");

        configure_ready_ = false ;
        counter = 0 ;
        while ( !configure_ready_ && counter < 10 ) {
            RCLCPP_INFO(this->get_logger(), "Try to activate controller");            
            configure_ready_ = send_activate_request();
            rclcpp::spin_some(this->get_node_base_interface());
            rclcpp::sleep_for(10ms); 
            counter++ ;            
        }

        
        // // 4. Verification Loop (The "Nudge" phase)
        // // We loop until the effort controller is active
        // bool is_ready = false;
        // while (rclcpp::ok() && !is_ready) {
        //     // Process any incoming service responses
        //     rclcpp::spin_some(this->get_node_base_interface());

        //     // Check if active
        //     is_ready = check_if_active();

        //     if (!is_ready) {
        //         // Nudge physics so the controller manager state machine can progress
        //        //  step_gazebo(5);
        //         // Sleep to prevent slamming the CPU and Gazebo service
        //         RCLCPP_INFO(this->get_logger(), "Not ready");
        //         rclcpp::sleep_for(200ms);
        //     }
        // }

        RCLCPP_INFO(this->get_logger(), "Initialization complete. Simulation paused and robot active.");
    }



private:

    bool check_if_active() {
        std::shared_ptr<controller_manager_msgs::srv::ListControllers::Request> request = 
            std::make_shared<controller_manager_msgs::srv::ListControllers::Request>();

        auto shared_future = list_client_->async_send_request(request).share();
        rclcpp::FutureReturnCode service_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), shared_future, 500ms) ;

        if ( service_result == rclcpp::FutureReturnCode::SUCCESS){
            std::shared_ptr<controller_manager_msgs::srv::ListControllers::Response> response = shared_future.get();

            //std::shared_ptr<controller_manager_msgs::srv::ListControllers::Response> response = future->get();
            bool effort_active = false;
            bool state_active = false;

            for (std::vector<controller_manager_msgs::msg::ControllerState>::iterator it = response->controller.begin(); 
                 it != response->controller.end(); ++it) {
                    RCLCPP_INFO_STREAM(this->get_logger(), "it " << it-> name) ;

                if ( it->name.compare("joint_effort_controller") == 0 && it->state.compare("active") == 0 ) effort_active = true;
                if ( it->name.compare("joint_state_broadcaster") == 0 && it->state.compare("active") == 0 ) state_active = true;
            }
            return ( effort_active && state_active );
        }
        else {
            RCLCPP_WARN(this->get_logger(), "list_controller is not ready") ;
            return false ;
        }
    }

    
    void send_load_request(std::string name) {

        std::shared_ptr<controller_manager_msgs::srv::LoadController::Request> request = 
            std::make_shared<controller_manager_msgs::srv::LoadController::Request>();
        request->name = name;

        RCLCPP_INFO(this->get_logger(), "Sending request to load: %s", name.c_str());       

        auto shared_future = load_client_->async_send_request(request).share();

        rclcpp::FutureReturnCode service_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), shared_future, 500ms) ;
        if ( service_result == rclcpp::FutureReturnCode::SUCCESS){
            RCLCPP_DEBUG_STREAM(this->get_logger(), "Successfully loaded " << name << " " << (this->now()).nanoseconds()/1e6 ) ;    
        } 
        else {
            RCLCPP_ERROR_STREAM(this->get_logger(), "Failed to load controller " << name << " " << (this->now()).nanoseconds()/1e6 ) ;    
        }
    }

        
    bool send_configure_request() {

        std::shared_ptr<controller_manager_msgs::srv::ConfigureController::Request> config_request_ = 
            std::make_shared<controller_manager_msgs::srv::ConfigureController::Request>();
        config_request_->name = "joint_state_broadcaster";

        rclcpp::Client<controller_manager_msgs::srv::ConfigureController>::SharedFuture config_future = 
            config_client_->async_send_request(config_request_).share();


        // Spin until configured
        rclcpp::FutureReturnCode service_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), config_future, 1s);
        
        if ( service_result == rclcpp::FutureReturnCode::SUCCESS ){
            RCLCPP_DEBUG_STREAM(this->get_logger(), "configure joint_state_broadcaster is successful " << (this->now()).nanoseconds()/1e6 ) ;    
        } 
        else {
            RCLCPP_ERROR_STREAM(this->get_logger(), "configure joint_state_broadcaster failed " << (this->now()).nanoseconds()/1e6 ) ;    
            return false ;
        }

        config_request_->name = "joint_effort_controller";
        config_future = config_client_->async_send_request(config_request_).share();
        service_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), config_future, 1s);
        if ( service_result == rclcpp::FutureReturnCode::SUCCESS ){
            RCLCPP_DEBUG_STREAM(this->get_logger(), "configure joint_effort_controller is successful " << (this->now()).nanoseconds()/1e6 ) ;    
        } 
        else {
            RCLCPP_ERROR_STREAM(this->get_logger(), "configure joint_effort_controller failed " << (this->now()).nanoseconds()/1e6 ) ;    
            return false ;
        }

        return true ;
    }

    bool send_activate_request() {

        // Call the SwitchController (Activate) service ...
        std::shared_ptr<controller_manager_msgs::srv::SwitchController::Request> request = std::make_shared<controller_manager_msgs::srv::SwitchController::Request>();
        std::vector<std::string> activate_list;

        activate_list.push_back("joint_state_broadcaster");
        activate_list.push_back("joint_effort_controller");
        request->activate_controllers = activate_list;
        request->strictness = controller_manager_msgs::srv::SwitchController::Request::STRICT;
        switch_client_->async_send_request(request) ;

        /*
        auto shared_future = switch_client_->async_send_request(request).share() ;        

        rclcpp::FutureReturnCode service_result = rclcpp::spin_until_future_complete(this->get_node_base_interface(), shared_future, 3s) ;

        RCLCPP_INFO_STREAM(this->get_logger(), "Done spinning " << (this->now()).nanoseconds()/1e6 ) ;    

        if ( service_result == rclcpp::FutureReturnCode::SUCCESS ){
            RCLCPP_INFO_STREAM(this->get_logger(), "activate joint_effort_controller is successful " << (this->now()).nanoseconds()/1e6 ) ;    
        } 
        else {
            RCLCPP_ERROR_STREAM(this->get_logger(), "activate joint_effort_controller failed " << (this->now()).nanoseconds()/1e6 ) ;    
            return false ;
        }
*/
        return true ;
    }

    void step_gazebo(uint32_t steps) {       
        gz_request_->world_control.step = true;
        gz_request_->world_control.multi_step = steps;
        gz_client_->async_send_request(gz_request_);
    }

    
    void pause_gazebo() {        
        gz_request_->world_control.pause = true;        
        gz_request_->world_control.step = false;
        gz_client_->async_send_request(gz_request_);
    }

    rclcpp::Client<controller_manager_msgs::srv::ConfigureController>::SharedPtr config_client_;
    rclcpp::Client<controller_manager_msgs::srv::ListControllers>::SharedPtr list_client_;
    rclcpp::Client<controller_manager_msgs::srv::LoadController>::SharedPtr load_client_;
    rclcpp::Client<controller_manager_msgs::srv::SwitchController>::SharedPtr switch_client_;    
    rclcpp::Client<ros_gz_interfaces::srv::ControlWorld>::SharedPtr gz_client_;

    std::shared_ptr<ros_gz_interfaces::srv::ControlWorld::Request> gz_request_ ;


    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr fake_joint_publisher_ ;
    sensor_msgs::msg::JointState fake_joint_msg_ ;
};




int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    std::shared_ptr<GazeboSpawnerManager> node = std::make_shared<GazeboSpawnerManager>();
    
    // Instead of rclcpp::spin(node), we call our custom loop
    node->run();
    
    // Keep node alive after init if needed, or shutdown
    rclcpp::shutdown();
    return 0;
}