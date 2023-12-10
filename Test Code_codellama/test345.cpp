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
