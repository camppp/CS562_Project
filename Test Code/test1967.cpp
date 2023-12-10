#include <iostream>
#include <string>

enum CallType { FromAPI, NotFromAPI };

class TaskService {
public:
    bool optimizeIndex() {
        // Simulated index optimization
        return true;  // Replace with actual index optimization logic
    }
};

class Response {
public:
    void addError(const std::string& message) {
        std::cout << "Error: " << message << std::endl;
    }
};

std::string handleRequest(TaskService* taskService, CallType callType) {
    if (!taskService) {
        return "Request failed, index task service not found";
    }

    if (callType != FromAPI) {
        if (!taskService->optimizeIndex()) {
            return "failed to optimize index.";
        }
        return "Request processed successfully";
    }

    if (callType == FromAPI) {
        if (!taskService->optimizeIndex()) {
            return "failed to optimize index.";
        }
        return "Request processed successfully";
    }

    return "";  // Placeholder for any other cases
}

int main() {
    TaskService* taskService = new TaskService();
    Response response;

    // Simulate handling requests
    std::cout << handleRequest(taskService, FromAPI) << std::endl;  // Output: Request processed successfully
    std::cout << handleRequest(taskService, NotFromAPI) << std::endl;  // Output: Request processed successfully

    delete taskService;
    return 0;
}
