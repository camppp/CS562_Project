#include <iostream>
#include <string>
#include <map>
#include <vector>

struct TaskExecAction {
    std::string programPath;
    std::string workingDir;
    std::vector<std::string> arguments;
};

struct TaskInfo {
    std::string name;
    std::string description;
    TaskExecAction action;
};

class TaskManager {
public:
    void registerTask(const std::string& taskName, const std::string& taskDescription, const std::string& programPath, const std::string& workingDir, const std::vector<std::string>& arguments) {
        TaskExecAction action;
        action.programPath = programPath;
        action.workingDir = workingDir;
        action.arguments = arguments;

        TaskInfo task;
        task.name = taskName;
        task.description = taskDescription;
        task.action = action;

        tasks.insert(std::make_pair(taskName, task));
    }

    bool isTaskRegistered(const std::string& taskName) {
        return tasks.find(taskName) != tasks.end();
    }

private:
    std::map<std::string, TaskInfo> tasks;
};
