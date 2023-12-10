#include <iostream>
#include <unordered_map>
#include <string>

int countUniqueSubstrings(const std::string& A, int wsize, int lsize) {
    int count = 0;
    std::unordered_map<std::string, int> uniqueSubstrings;

    for (int i = 0; (i + wsize * lsize - 1) < A.size(); ++i) {
        std::unordered_map<std::string, int> tempMap;
        int j = 0;
        while (j < lsize) {
            std::string temp = A.substr(i + j * wsize, wsize);
            tempMap[temp]++;
            if (tempMap[temp] == 1) {
                uniqueSubstrings[temp]++;
            }
            j++;
        }
    }

    return uniqueSubstrings.size();
}

int main() {
    std::string A = "abracadabra";
    int wsize = 2;
    int lsize = 3;
    std::cout << "Count of unique substrings: " << countUniqueSubstrings(A, wsize, lsize) << std::endl;
    return 0;
}
