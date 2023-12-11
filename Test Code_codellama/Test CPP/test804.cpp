#include <iostream>
#include <string>

int minOperations(const std::string& s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            count++;
        }
    }
    return count % 2 == 0 ? count / 2 : count / 2 + 1;
}
