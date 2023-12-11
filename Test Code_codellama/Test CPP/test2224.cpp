#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

// A class to represent a parsed URL
class URL {
public:
    string host;
    string path;

    URL(string url) {
        // Parse the URL and extract the host and path parts
        size_t pos = url.find("://");
        if (pos != string::npos) {
            host = url.substr(pos + 3);
            pos = host.find("/");
            if (pos != string::npos) {
                host = host.substr(0, pos);
                path = url.substr(pos + 1);
            }
        }
    }

    // Calculate the hash of the host part of the URL
    size_t host_hash() {
        return std::hash<std::string>{}(host);
    }
};

int main() {
    // Open the input file
    ifstream input_file("input.txt");

    // Create a set to store unique host hashes
    unordered_set<size_t> hosts;

    // Read URLs from the input file and process them line by line
    string line;
    while (getline(input_file, line)) {
        // Create a URL object from the current line
        URL url(line);

        // Calculate the hash of the host part of the URL
        size_t host_hash = url.host_hash();

        // Check if the calculated host hash is already present in the set
        if (hosts.find(host_hash) == hosts.end()) {
            // If not, add it to the set
            hosts.insert(host_hash);
        }
    }

    // Print the unique hosts
    for (auto host : hosts) {
        cout << host << endl;
    }

    return 0;
}
