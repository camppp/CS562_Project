double calculateElapsedTime(rclcpp::Time start, rclcpp::Time end) {
  return (end - start).to_chrono<std::chrono::milliseconds>().count();
}
