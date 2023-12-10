#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    void func() {
        cout << "This is Person, this is " << this << endl;
    }
};

class Manager : public Person {
private:
    int salary;
    string test;
public:
    Manager(int salary, string test) : salary(salary), test(test) {}

    void set_salary_test(int salary, string test) {
        this->salary = salary;
        this->test = test;
    }

    void get_salary() {
        cout << "salary is " << salary << ", test is " << test << endl;
    }

    void func() {
        Person::func();
        cout << "This is Manager, this is " << this << endl;
    }

    void func_1(string name) {
        cout << "This is Manager::func_1(), this is " << this << endl;
    }

    void func_1() {
        cout << "This is Manager::func_1() without name, this is " << this << endl;
    }
};

int main() {
    Manager manager(50000, "evaluation");
    manager.get_salary();
    manager.set_salary_test(60000, "bonus");
    manager.get_salary();
    manager.func();
    manager.func_1("John");
    manager.func_1();
    return 0;
}
