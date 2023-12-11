#include <memory>

class ActivityDataService {
    // Assume this class has some methods and properties
};

namespace component_updater {
    bool IsPerUserInstall() {
        // Assume this function returns a boolean value indicating whether the software is installed per user
        return true;
    }
}

class ChromeUpdateClientConfig {
public:
    ChromeUpdateClientConfig(std::unique_ptr<ActivityDataService> activity_data_service)
        : activity_data_service_(std::move(activity_data_service)) {}

    ActivityDataService* GetActivityDataService() const {
        return activity_data_service_.get();
    }

    bool IsPerUserInstall() const {
        return component_updater::IsPerUserInstall();
    }

private:
    std::unique_ptr<ActivityDataService> activity_data_service_;
};