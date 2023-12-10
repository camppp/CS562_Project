#include <iostream>
#include <cstring>

class Person {
private:
    int code;
    char* name;

public:
    Person() {}

    ~Person() {
        delete[] name;
    }

    Person(const Person& other) {
        code = other.code;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    void setCode(int code) {
        this->code = code;
    }

    void setName(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
};

int main() {
    Person person1;
    person1.setCode(1001);
    person1.setName("Alice");

    Person person2 = person1; // Copy constructor should be called

    return 0;
}
