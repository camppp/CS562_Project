#include <iostream>
#include <string>

// Define the Task class
class Task {
public:
    std::string type;
    std::string data;

    Task(std::string type, std::string data) : type(type), data(data) {}
};

// Implement the L2MdApi class
class L2MdApi {
public:
    void processHeartBeatWarning(Task task) {
        if (task.type == "heartbeat") {
            processHeartbeat(task.data);
        } else if (task.type == "warning") {
            processWarning(task.data);
        } else {
            std::cout << "Unknown task type: " << task.type << std::endl;
        }
    }

private:
    void processHeartbeat(const std::string& data) {
        std::cout << "Processing heartbeat: " << data << std::endl;
        // Add logic to handle heartbeat processing
    }

    void processWarning(const std::string& data) {
        std::cout << "Processing warning: " << data << std::endl;
        // Add logic to handle warning processing
    }
};

int main() {
    // Create an instance of L2MdApi and process tasks
    L2MdApi api;
    Task heartbeatTask("heartbeat", "heartbeat_data");
    Task warningTask("warning", "warning_data");

    api.processHeartBeatWarning(heartbeatTask);
    api.processHeartBeatWarning(warningTask);

    return 0;
}
