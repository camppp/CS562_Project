#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <base64.h>

using namespace std;

vector<pair<string, string>> parseSoftwareVersions(const vector<pair<string, string>>& pairs) {
    vector<pair<string, string>> result;

    for (const auto& pair : pairs) {
        string version = pair.first;
        string encoded = pair.second;

        // Remove any newline characters from the version string
        version.erase(remove(version.begin(), version.end(), '\n'), version.end());

        // Remove any whitespace characters from the encoded string
        encoded.erase(remove(encoded.begin(), encoded.end(), ' '), encoded.end());

        // Decode the encoded string using base64
        string decoded = base64_decode(encoded);

        // Add the correctly formatted version and decoded string to the result vector
        result.push_back(make_pair(version, decoded));
    }

    return result;
}
