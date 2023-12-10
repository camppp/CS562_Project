class CustomServer : public Server_impl {
public:
  void shutdown() {
    // Log a message indicating the initiation of the shutdown process
    std::cout << "Initiating server shutdown" << std::endl;

    // Call the shutdown method of the orb_ object
    orb_->shutdown();
  }
};
