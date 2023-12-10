#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> generateNewConnections(int numPotentialConnections, int numToGenerate) {
    vector<string> connections;
    for (int i = 0; i < numPotentialConnections; i++) {
        connections.push_back("Connection " + to_string(i));
    }
    random_shuffle(connections.begin(), connections.end());
    return connections.begin(), connections.begin() + numToGenerate;
}

int main() {
    int numPotentialConnections = 20;
    int numToGenerate = 5;
    vector<string> connections = generateNewConnections(numPotentialConnections, numToGenerate);
    for (string connection : connections) {
        cout << connection << endl;
    }
    return 0;
}
