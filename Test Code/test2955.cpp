#include <iostream>

// Define the possible application statuses
enum ApplicationStatus {
    APP_RUN,
    APP_QUIT,
    // Add other statuses as needed
};

class ApplicationStatusManager {
private:
    ApplicationStatus mStatus;

public:
    // Constructor to initialize the application status
    ApplicationStatusManager() : mStatus(APP_RUN) {}

    // Method to handle Windows messages and update the application status
    void handleMessage(int windowsMessage) {
        switch (windowsMessage) {
            case WM_QUIT:
            case WM_DESTROY:
            case WM_CLOSE:
                mStatus = APP_QUIT;
                break;
            // Handle other Windows messages if needed
        }
    }

    // Method to get the current application status
    ApplicationStatus getStatus() const {
        return mStatus;
    }
};

int main() {
    ApplicationStatusManager statusManager;

    // Simulate handling Windows messages
    statusManager.handleMessage(WM_CLOSE);
    std::cout << "Current application status: " << statusManager.getStatus() << std::endl;

    statusManager.handleMessage(WM_DESTROY);
    std::cout << "Current application status: " << statusManager.getStatus() << std::endl;

    statusManager.handleMessage(WM_QUIT);
    std::cout << "Current application status: " << statusManager.getStatus() << std::endl;

    return 0;
}
