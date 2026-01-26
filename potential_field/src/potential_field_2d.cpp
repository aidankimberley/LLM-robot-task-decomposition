#include "rclcpp/rclcpp.hpp"
#include "potential_field/PotentialField2D.hpp"

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    std::shared_ptr<PotentialField2D> node = std::make_shared<PotentialField2D>("potential_field_2d");
    rclcpp::Rate loop_rate(500); //hz
    while(rclcpp::ok()){
        node->update();
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}