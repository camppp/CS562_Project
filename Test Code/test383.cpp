#include <iostream>
#include <string>

struct Task {
    std::string description;
    bool completed;
    Task* next;

    Task(const std::string& desc) : description(desc), completed(false), next(nullptr) {}
};

class TodoList {
private:
    Task* head;

public:
    TodoList() : head(nullptr) {}

    // Add a new task to the to-do list
    void addTask(const std::string& description) {
        Task* newTask = new Task(description);
        if (head == nullptr) {
            head = newTask;
        } else {
            Task* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newTask;
        }
    }

    // Remove a task from the to-do list
    void removeTask(const std::string& description) {
        Task* current = head;
        Task* prev = nullptr;
        while (current != nullptr && current->description != description) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Task not found" << std::endl;
            return;
        }
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }

    // Display all tasks in the to-do list
    void displayTasks() {
        Task* current = head;
        while (current != nullptr) {
            std::cout << current->description << " - " << (current->completed ? "Completed" : "Pending") << std::endl;
            current = current->next;
        }
    }

    // Mark a task as completed
    void markTaskAsCompleted(const std::string& description) {
        Task* current = head;
        while (current != nullptr && current->description != description) {
            current = current->next;
        }
        if (current != nullptr) {
            current->completed = true;
        } else {
            std::cout << "Task not found" << std::endl;
        }
    }
};

int main() {
    TodoList todoList;
    todoList.addTask("Complete programming problem");
    todoList.addTask("Prepare for interview");
    todoList.displayTasks();
    todoList.markTaskAsCompleted("Complete programming problem");
    todoList.removeTask("Prepare for interview");
    todoList.displayTasks();
    return 0;
}
