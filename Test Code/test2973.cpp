// CustomException.h
#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <exception>
#include <string>

class CustomException : public std::exception {
public:
    CustomException(const char* errorMessage) : message(errorMessage) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif // CUSTOMEXCEPTION_H
