#include <iostream>
#include <cstring>

class Person {
private:
    int code;
    char* name;

public:
    // Destructor to release memory for name
    ~Person() {
        if (name != nullptr) {
            delete[] name;
            name = nullptr;
        }
    }

    // Copy constructor for deep copying
    Person(const Person& person) {
        std::cout << std::endl << "Calling COPY-CSTR";
        code = person.code;
        if (person.name != nullptr) {
            name = new char[strlen(person.name) + 1];
            strcpy(name, person.name);
        } else {
            name = nullptr;
        }
    }

    // Setter for code
    void setCode(int newCode) {
        code = newCode;
    }

    // Setter for name
    void setName(const char* newName) {
        if (name != nullptr) {
            delete[] name;
        }
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
};

int main() {
    Person person1;
    person1.setCode(1001);
    person1.setName("Alice");

    Person person2 = person1; // Copy constructor should be called

    return 0;
}
