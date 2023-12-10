#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <filesystem>

struct TaskExecAction {
    std::string application_path;
    std::filesystem::path working_dir;
    std::string arguments;
};

struct TaskInfo {
    std::string name;
    std::string description;
    std::vector<TaskExecAction> exec_actions;
};

class TaskManager {
private:
    std::map<std::string, TaskInfo> tasks_;
    bool register_task_called_ = false;

public:
    void registerTask(const std::string& taskName, const std::string& taskDescription,
                      const std::string& programPath, const std::string& workingDir,
                      const std::string& arguments) {
        TaskExecAction task_action = {
            programPath,
            workingDir,
            arguments
        };

        std::vector<TaskExecAction> task_actions = {task_action};

        TaskInfo task_info;
        task_info.name = taskName;
        task_info.description = taskDescription;
        task_info.exec_actions = task_actions;

        tasks_[taskName] = task_info;

        register_task_called_ = true;
    }

    bool isTaskRegistered(const std::string& taskName) {
        return tasks_.count(taskName) > 0;
    }
};

int main() {
    TaskManager taskManager;
    taskManager.registerTask("Task1", "Description for Task1", "/path/to/program1", "/path/to/working/dir", "-arg1 -arg2");
    taskManager.registerTask("Task2", "Description for Task2", "/path/to/program2", "/path/to/working/dir", "-arg3 -arg4");

    std::cout << "Task1 is registered: " << (taskManager.isTaskRegistered("Task1") ? "Yes" : "No") << std::endl;
    std::cout << "Task3 is registered: " << (taskManager.isTaskRegistered("Task3") ? "Yes" : "No") << std::endl;

    return 0;
}
