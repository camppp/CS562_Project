#include <iostream>
#include <string>
#include <random>

using namespace std;

string GenerateRequestId() {
    string prefix = "REQ-";
    string suffix = "-2022";
    string randomString = "";

    // Generate a random 6-character alphanumeric string
    randomString = randomString.substr(0, 6);
    for (int i = 0; i < 6; i++) {
        randomString[i] = 'A' + rand() % 26;
    }

    // Combine the prefix, random string, and suffix
    string requestId = prefix + randomString + suffix;

    return requestId;
}
