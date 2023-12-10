#include <iostream>
#include <vector>
#include <string>

std::string join(const std::vector<std::string>& components) {
    std::string result;
    for (const std::string& str : components) {
        result += str;
    }
    return result;
}

int main() {
    // Test cases
    std::vector<std::string> test1 = {"Hello", "World", "!"};
    std::vector<std::string> test2 = {"This", "is", "a", "test"};
    
    std::cout << "Test 1: " << join(test1) << std::endl;  // Output: HelloWorld!
    std::cout << "Test 2: " << join(test2) << std::endl;  // Output: Thisisatest
    
    return 0;
}
