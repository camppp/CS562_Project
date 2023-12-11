// register_types.h
#ifndef REGISTER_TYPES_H
#define REGISTER_TYPES_H

class User {
private:
    std::string name;
    std::string email;
    int age;

public:
    User(std::string name, std::string email, int age) : name(name), email(email), age(age) {}

    void registerUser(std::string name, std::string email, int age) {
        this->name = name;
        this->email = email;
        this->age = age;
    }

    void retrieveAndDisplayUserInfo() {
        std::cout << "Name: " << name << ", Email: " << email << ", Age: " << age << std::endl;
    }
};

#endif // REGISTER_TYPES_H
