#include <iostream>
#include <string>
#include <unordered_map>

struct EmployeeInfo {
    std::string name;
    int employeeID;
    double salary;
};

class EmployeeManager {
private:
    std::unordered_map<int, EmployeeInfo> employeeMap;

public:
    void addEmployee(const std::string& name, int employeeID, double salary) {
        EmployeeInfo newEmployee = {name, employeeID, salary};
        employeeMap[employeeID] = newEmployee;
    }

    void updateSalary(int employeeID, double newSalary) {
        if (employeeMap.find(employeeID) != employeeMap.end()) {
            employeeMap[employeeID].salary = newSalary;
        } else {
            std::cout << "Employee with ID " << employeeID << " not found." << std::endl;
        }
    }

    void retrieveEmployeeInfo(int employeeID) {
        if (employeeMap.find(employeeID) != employeeMap.end()) {
            EmployeeInfo& employee = employeeMap[employeeID];
            std::cout << "Name: " << employee.name << std::endl;
            std::cout << "Employee ID: " << employee.employeeID << std::endl;
            std::cout << "Salary: " << employee.salary << std::endl;
        } else {
            std::cout << "Employee with ID " << employeeID << " not found." << std::endl;
        }
    }
};

int main() {
    EmployeeManager manager;

    // Adding new employees
    manager.addEmployee("John Doe", 1001, 50000.0);
    manager.addEmployee("Jane Smith", 1002, 60000.0);

    // Updating employee salary
    manager.updateSalary(1001, 55000.0);

    // Retrieving employee information
    manager.retrieveEmployeeInfo(1001);
    manager.retrieveEmployeeInfo(1003);  // Non-existent employee

    return 0;
}
