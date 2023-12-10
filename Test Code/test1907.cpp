#include <iostream>
#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    int age;

public:
    Person(std::string firstName, std::string lastName, int age) : firstName(firstName), lastName(lastName), age(age) {}

    std::string toString() {
        return firstName + " " + lastName + ", " + std::to_string(age);
    }
};

class Employee : public Person {
private:
    int staffNumber;

public:
    Employee(std::string firstName, std::string lastName, int age, int staffNumber) : Person(firstName, lastName, age), staffNumber(staffNumber) {}

    ~Employee() {
        // Implement any necessary cleanup code for the Employee class
    }

    std::string toString() {
        return Person::toString() + ", " + std::to_string(staffNumber);
    }
};

int main() {
    Employee emp("John", "Doe", 30, 1001);
    std::cout << emp.toString() << std::endl;  // Output: John Doe, 30, 1001
    return 0;
}
