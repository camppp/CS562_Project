// register_types.h
#ifndef REGISTER_TYPES_H
#define REGISTER_TYPES_H

#include <iostream>
#include <string>

class User {
private:
    std::string name;
    std::string email;
    int age;

public:
    User() : name(""), email(""), age(0) {}

    void registerUser(const std::string& userName, const std::string& userEmail, int userAge) {
        name = userName;
        email = userEmail;
        age = userAge;
    }

    void displayUserInfo() {
        std::cout << "Name: " << name << ", Email: " << email << ", Age: " << age << std::endl;
    }
};

#endif // REGISTER_TYPES_H
