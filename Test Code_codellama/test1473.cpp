#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    // Open the text file
    std::ifstream file("sample_text.txt");

    // Create a map to store the counts of each word
    std::map<std::string, int> counts;

    // Read the text file and count the occurrences of each word
    std::string word;
    while (file >> word) {
        if (word == "License") {
            counts["License"]++;
        } else if (word == "software") {
            counts["software"]++;
        } else if (word == "distributed") {
            counts["distributed"]++;
        }
    }

    // Output the counts
    for (const auto& count : counts) {
        std::cout << "Occurrences of '" << count.first << "': " << count.second << std::endl;
    }

    return 0;
}
