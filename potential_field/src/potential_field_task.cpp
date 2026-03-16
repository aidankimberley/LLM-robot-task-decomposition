#include "rclcpp/rclcpp.hpp"
#include "potential_field/PotentialFieldTask.hpp"

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    std::shared_ptr<PotentialFieldTask> node = std::make_shared<PotentialFieldTask>("potential_field_task");
    int publish_rate = node->get_parameter("publish_rate").as_int();
    rclcpp::Logger logger = node->get_logger();
    logger.set_level(rclcpp::Logger::Level::Info);

    rclcpp::Rate loop_rate(publish_rate); //hz
    while(rclcpp::ok()){
        node->update();
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}