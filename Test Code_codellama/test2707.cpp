// Logger plugin for benchmarking
class LoggerPlugin {
 public:
  // Constructor
  LoggerPlugin() {}

  // Destructor
  ~LoggerPlugin() {}

  // Set the active status of the plugin
  void setActive(bool active) {
    this->active_ = active;
  }

  // Log a message
  void log(const std::string& message) {
    if (this->active_) {
      // Implement logging functionality here
    }
  }

 private:
  bool active_ = false;
};

// Benchmarking function for the logger plugin
void LOGGER_logstatus_plugin(LoggerPlugin* plugin) {
  // Set the active status of the plugin to true
  plugin->setActive(true);

  // Benchmark the logging functionality
  for (int i = 0; i < 1000000; i++) {
    plugin->log("This is a test message");
  }
}

// Benchmarking function for the logger plugin
void LOGGER_logstring_plugin(LoggerPlugin* plugin) {
  // Set the active status of the plugin to true
  plugin->setActive(true);

  // Benchmark the logging functionality
  for (int i = 0; i < 1000000; i++) {
    plugin->log("This is a test message with a string");
  }
}

int main() {
  // Create a logger plugin
  LoggerPlugin* logger = new LoggerPlugin();

  // Benchmark the logger plugin
  LOGGER_logstatus_plugin(logger);
  LOGGER_logstring_plugin(logger);

  // Clean up
  delete logger;

  return 0;
}
