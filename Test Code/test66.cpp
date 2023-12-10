#include <memory>

namespace update_client {
  class ActivityDataService {
    // Implementation of ActivityDataService class
  };
}

namespace component_updater {
  bool IsPerUserInstall() {
    // Implementation of IsPerUserInstall function
    return true;  // Placeholder return value for demonstration
  }
}

class ChromeUpdateClientConfig {
public:
  ChromeUpdateClientConfig(std::unique_ptr<update_client::ActivityDataService> activity_data_service)
    : activity_data_service_(std::move(activity_data_service)) {}

  update_client::ActivityDataService* GetActivityDataService() const {
    return activity_data_service_.get();
  }

  bool IsPerUserInstall() const {
    return component_updater::IsPerUserInstall();
  }

private:
  std::unique_ptr<update_client::ActivityDataService> activity_data_service_;
};

int main() {
  // Example usage
  std::unique_ptr<update_client::ActivityDataService> activity_data_service = std::make_unique<update_client::ActivityDataService>();
  ChromeUpdateClientConfig config(std::move(activity_data_service));

  update_client::ActivityDataService* activity_data_service_ptr = config.GetActivityDataService();
  bool is_per_user_install = config.IsPerUserInstall();

  // Further usage of activity_data_service_ptr and is_per_user_install
  return 0;
}
