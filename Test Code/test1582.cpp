#include <chrono>

double calculateElapsedTime(rclcpp::Time start, rclcpp::Time end) {
    std::chrono::nanoseconds elapsed_ns = end.nanoseconds() - start.nanoseconds();
    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_ns).count();
}
