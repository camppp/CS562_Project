#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct AgentVersion {
    string agent;
    string version;
};

bool compareAgentVersions(const AgentVersion& a, const AgentVersion& b) {
    if (a.version == b.version) {
        return a.agent < b.agent;
    }
    return a.version < b.version;
}

vector<AgentVersion> sortAgentVersions(const vector<AgentVersion>& versions) {
    vector<AgentVersion> sortedVersions = versions;
    sort(sortedVersions.begin(), sortedVersions.end(), compareAgentVersions);
    return sortedVersions;
}

int main() {
    vector<AgentVersion> versions = {
        {"A", "1.0"},
        {"B", "2.0"},
        {"C", "1.5"},
        {"A", "1.5"}
    };

    vector<AgentVersion> sortedVersions = sortAgentVersions(versions);

    for (const AgentVersion& version : sortedVersions) {
        cout << version.agent << " " << version.version << endl;
    }

    return 0;
}
