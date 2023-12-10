#include <iostream>
#include <string>
#include <map>

// Structure to hold employee information
struct EmployeeInfo {
    std::string name;
    int employeeID;
    double salary;
};

// Function to add a new employee to the system
void addEmployee(const EmployeeInfo& employee) {
    // Create a new map entry for the employee
    std::map<int, EmployeeInfo> employees;
    employees[employee.employeeID] = employee;
}

// Function to update an existing employee's salary
void updateEmployeeSalary(int employeeID, double salary) {
    // Find the employee in the map
    std::map<int, EmployeeInfo>::iterator it = employees.find(employeeID);
    if (it != employees.end()) {
        // Update the salary
        it->second.salary = salary;
    }
}

// Function to retrieve an employee's details based on their ID
EmployeeInfo getEmployee(int employeeID) {
    // Find the employee in the map
    std::map<int, EmployeeInfo>::iterator it = employees.find(employeeID);
    if (it != employees.end()) {
        // Return the employee's details
        return it->second;
    }
    return EmployeeInfo();
}

int main() {
    // Create a map to store the employees
    std::map<int, EmployeeInfo> employees;

    // Add a new employee to the system
    EmployeeInfo employee1 = { "John Doe", 1234, 50000.0 };
    addEmployee(employee1);

    // Update an existing employee's salary
    updateEmployeeSalary(1234, 60000.0);

    // Retrieve an employee's details based on their ID
    EmployeeInfo employee2 = getEmployee(1234);
    std::cout << "Employee 2: " << employee2.name << " " << employee2.employeeID << " " << employee2.salary << std::endl;

    return 0;
}
