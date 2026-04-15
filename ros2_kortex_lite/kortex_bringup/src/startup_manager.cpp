#include <chrono>
#include <memory>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "controller_manager_msgs/srv/list_controllers.hpp"
#include "ros_gz_interfaces/srv/control_world.hpp"

using namespace std::chrono_literals;

class GazeboStartupManager : public rclcpp::Node {

    public:
        
        GazeboStartupManager() : Node("gazebo_startup_manager") {

            // Clients for checking controllers and pausing gazebo
            controller_client_ = this->create_client<controller_manager_msgs::srv::ListControllers>("/controller_manager/list_controllers");
            
            // service to pause/unpause gazebo
            pause_client_ = this->create_client<ros_gz_interfaces::srv::ControlWorld>("/world/empty/control");

            // Start the monitoring loop
            //timer_ = this->create_wall_timer(500ms, std::bind(&GazeboAutoPause::monitor, this));

            controller_manager_request_ = std::make_shared<controller_manager_msgs::srv::ListControllers::Request>() ;
            pause_gazebo_request_       = std::make_shared<ros_gz_interfaces::srv::ControlWorld::Request>() ;
            pause_gazebo_request_ -> world_control.pause = true;

            RCLCPP_INFO(this->get_logger(), "Node started. Waiting for controllers to activate...");
        }

        void monitor() {
            if ( !controller_client_->service_is_ready() ) {
                RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Waiting for controller_manager...");
                return;
            }

            // controller_manager is ready
            //auto request = std::make_shared<controller_manager_msgs::srv::ListControllers::Request>();

            controller_client_->async_send_request(controller_manager_request_, 
                std::bind(&GazeboStartupManager::controller_callback, this, std::placeholders::_1));

        }


    private:

        void controller_callback(rclcpp::Client<controller_manager_msgs::srv::ListControllers>::SharedFuture future) {
            auto response = future.get();
            bool all_active = false;

            for (const auto & ctrl : response->controller) {
                // Check for your specific broadcaster
                if ( ctrl.name == "joint_state_broadcaster" && ctrl.state == "active") {
                    all_active = true;
                    break;
                }
            }

            if (all_active && !pause_triggered_) {
                RCLCPP_INFO(this->get_logger(), "Controllers are ACTIVE. Sending pause command...");
                trigger_pause();
                pause_triggered_ = true;
                //timer_->cancel(); // Stop polling
            }
        }

        void trigger_pause() {

            if (!pause_client_->wait_for_service(1s)) {
                RCLCPP_ERROR(this->get_logger(), "Gazebo pause service not available! Is the bridge running?");
                return;
            }

            //auto request = std::make_shared<ros_gz_interfaces::srv::ControlWorld::Request>();
            // request->world_control.pause = true;

            pause_client_->async_send_request(pause_gazebo_request_, [this](rclcpp::Client<ros_gz_interfaces::srv::ControlWorld>::SharedFuture future) {
                if (future.get()->success) {
                    RCLCPP_INFO(this->get_logger(), "Gazebo successfully paused.");
                    rclcpp::shutdown();
                }
            });
        }

        rclcpp::Client<controller_manager_msgs::srv::ListControllers>::SharedPtr controller_client_;
        rclcpp::Client<ros_gz_interfaces::srv::ControlWorld>::SharedPtr pause_client_;
        //rclcpp::TimerBase::SharedPtr timer_;

        std::shared_ptr<controller_manager_msgs::srv::ListControllers::Request> controller_manager_request_ ;
        std::shared_ptr<ros_gz_interfaces::srv::ControlWorld::Request> pause_gazebo_request_ ;

        bool pause_triggered_ = false;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);

    std::shared_ptr<GazeboStartupManager>  node = std::make_shared<GazeboStartupManager>();

    rclcpp::Rate loop_rate(500);

    while ( rclcpp::ok() ){
      
        // update
        //if ( node_handle-> isReady() ) {
        node-> monitor() ;
        //}

        // call all the callbacks waiting to be called 
        //rclcpp::spin_some(node_handle);

        // sleep for any time remaining to the publish rate
        loop_rate.sleep();       
    }
    
    RCLCPP_INFO(node->get_logger(), "startup manager done") ;
    rclcpp::shutdown();
    return 0;
}