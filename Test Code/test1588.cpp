#include <iostream>
#include <string>
#include <unordered_map>
#include <json/json.h> // Assuming the use of a JSON library

class SystemStatus {
private:
    bool m_setupFailed;
    int m_shuttingDown;
    bool m_startFailed;
    bool m_setupFailedHasBeenSet;
    bool m_shuttingDownHasBeenSet;
    bool m_startFailedHasBeenSet;

public:
    SystemStatus() : m_setupFailed(false), m_shuttingDown(0), m_startFailed(false),
                     m_setupFailedHasBeenSet(false), m_shuttingDownHasBeenSet(false), m_startFailedHasBeenSet(false) {}

    void ProcessStatusJson(const Json::Value& jsonValue) {
        if (jsonValue.isMember("SetupFailed")) {
            m_setupFailed = jsonValue["SetupFailed"].asBool();
            m_setupFailedHasBeenSet = true;
        }

        if (jsonValue.isMember("ShuttingDown")) {
            m_shuttingDown = jsonValue["ShuttingDown"].asInt();
            m_shuttingDownHasBeenSet = true;
        }

        if (jsonValue.isMember("StartFailed")) {
            m_startFailed = jsonValue["StartFailed"].asBool();
            m_startFailedHasBeenSet = true;
        }
    }

    bool GetSetupFailed() const {
        if (m_setupFailedHasBeenSet) {
            return m_setupFailed;
        }
        return false; // Default value if not set
    }

    int GetShuttingDown() const {
        if (m_shuttingDownHasBeenSet) {
            return m_shuttingDown;
        }
        return 0; // Default value if not set
    }

    bool GetStartFailed() const {
        if (m_startFailedHasBeenSet) {
            return m_startFailed;
        }
        return false; // Default value if not set
    }
};

int main() {
    // Example usage
    std::string jsonStr = R"({"SetupFailed": true, "ShuttingDown": 1, "StartFailed": false})";
    Json::Value jsonValue;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(jsonStr, jsonValue);
    if (parsingSuccessful) {
        SystemStatus status;
        status.ProcessStatusJson(jsonValue);
        std::cout << "SetupFailed: " << status.GetSetupFailed() << std::endl;
        std::cout << "ShuttingDown: " << status.GetShuttingDown() << std::endl;
        std::cout << "StartFailed: " << status.GetStartFailed() << std::endl;
    } else {
        std::cerr << "Failed to parse JSON" << std::endl;
    }
    return 0;
}
