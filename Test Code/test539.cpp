#include <iostream>
#include <string>

class PatternDetector {
public:
    int appId;

    void setAppId(const std::string& clientID) {
        // Assuming clientID is in the format "clientXXX" where XXX is the ID
        if (clientID.substr(0, 6) == "client") {
            try {
                appId = std::stoi(clientID.substr(6));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid client ID format: " << clientID << std::endl;
            }
        } else {
            std::cerr << "Invalid client ID format: " << clientID << std::endl;
        }
    }
};

int main() {
    PatternDetector* detector = new PatternDetector();
    detector->setAppId("client123");
    std::cout << "App ID set to: " << detector->appId << std::endl;  // Output: App ID set to: 123
    return 0;
}
