#include "rclcpp/rclcpp.hpp"
#include "kinematic_controller/KinematicController.hpp"

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    std::shared_ptr<KinematicController> node = std::make_shared<KinematicController>("kinematic_controller");

    rclcpp::Logger logger = node->get_logger();
    logger.set_level(rclcpp::Logger::Level::Info);

    rclcpp::Rate loop_rate(500); //hz
    while(rclcpp::ok()){
        rclcpp::spin_some(node);
        node->SendCommands();
        loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}