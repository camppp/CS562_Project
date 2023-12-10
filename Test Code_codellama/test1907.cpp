class Person {
public:
    Person(string firstName, string lastName, int age) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
    }

    virtual ~Person() {}

    string toString() {
        return "First Name: " + firstName + "\nLast Name: " + lastName + "\nAge: " + to_string(age);
    }

private:
    string firstName;
    string lastName;
    int age;
};

class Employee : public Person {
public:
    Employee(string firstName, string lastName, int age, int staffNumber) : Person(firstName, lastName, age) {
        this->staffNumber = staffNumber;
    }

    ~Employee() {}

    string toString() {
        return Person::toString() + "\nStaff Number: " + to_string(staffNumber);
    }

private:
    int staffNumber;
};
