#include <iostream>
#include <string>

std::string processText(const std::string& input) {
    std::string temp = "SRTF";
    for (char c : input) {
        if (!((c > 'A' && c < 'Z') && (input[&c - &input[0] - 1] > 'A' && input[&c - &input[0] - 1] < 'Z')) &&
            !((c > 'a' && c < 'z') && c != ' ')) {
            temp += c;
        }
    }
    return temp;
}

int main() {
    std::string input = "Sample input text";  // Replace with actual input text
    std::string processedText = processText(input);
    std::cout << "Processed Text: " << processedText << std::endl;
    return 0;
}
