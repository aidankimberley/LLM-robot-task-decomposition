#include <rclcpp/rclcpp.hpp>
#include <potential_field/PotentialFieldActionServer.hpp>

int main(int argc, char** argv) {

    rclcpp::init(argc, argv);

    std::shared_ptr<PotentialFieldActionServer> node_handle = std::make_shared<PotentialFieldActionServer>();
    
    rclcpp::Rate loop_rate(500); // hz
	
    while ( rclcpp::ok() ){
        
        try {
            if (node_handle->recieved_first_pose_ && !node_handle->active_action_call_) {
                node_handle->homing();
            }
            // call all the callbacks waiting to be called 
            rclcpp::spin_some(node_handle);

            // sleep for any time remaining to the publish rate
            loop_rate.sleep();       
        }
        catch (const std::runtime_error& e) {
            RCLCPP_ERROR(node_handle->get_logger(), "run-time error") ;
            RCLCPP_ERROR(node_handle->get_logger(), e.what()) ;
            rclcpp::shutdown();
            return 1;
        }
    }

	return 0;
}
