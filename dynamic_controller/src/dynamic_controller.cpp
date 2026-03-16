#include "rclcpp/rclcpp.hpp"
#include "dynamic_controller/DynamicController.hpp"

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    std::shared_ptr<DynamicController> node = std::make_shared<DynamicController>("dynamic_controller");

    rclcpp::Logger logger = node->get_logger();
    logger.set_level(rclcpp::Logger::Level::Info);

    rclcpp::Rate loop_rate(500); //hz
    while(rclcpp::ok()){
        rclcpp::spin_some(node);
        node->calculate_joint_torque();
        loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}