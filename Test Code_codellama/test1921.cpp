#include <iostream>

class CTask {
private:
    int m_ID; // Unique ID for the task

public:
    // Constructor to initialize the task with a unique ID
    CTask(int id) : m_ID(id) {}

    // Method to retrieve the ID of the task
    int getID() {
        return m_ID;
    }
};

int main() {
    // Create a task with ID 1001
    CTask task1(1001);

    // Retrieve and print the ID of the task
    std::cout << "Task ID: " << task1.getID() << std::endl;

    return 0;
}
