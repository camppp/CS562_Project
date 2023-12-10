#include <iostream>
#include <fstream>
#include <vector>

// Define the custom exception classes here

// FileOpenException class
class FileOpenException : public std::exception {
public:
    const char* what() const throw() {
        return "Error: Unable to open the file";
    }
};

// InvalidDataException class
class InvalidDataException : public std::exception {
public:
    const char* what() const throw() {
        return "Error: Invalid data found in the file";
    }
};

int main() {
    try {
        std::ifstream file("input.txt");
        if (!file.is_open()) {
            throw FileOpenException();
        }

        std::vector<int> numbers;
        int num;
        while (file >> num) {
            numbers.push_back(num);
        }

        if (!file.eof()) {
            throw InvalidDataException();
        }

        int sum = 0;
        for (int n : numbers) {
            sum += n;
        }
        std::cout << "Sum of the integers: " << sum << std::endl;
    }
    catch (FileOpenException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (InvalidDataException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
