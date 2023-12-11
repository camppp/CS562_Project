#include <iostream>
#include <vector>

using namespace std;

vector<int> simulateScheduler(const vector<int>& processes, int timeSlice) {
    vector<int> result;
    int currentProcess = 0;
    int currentTime = 0;

    while (currentTime < processes.size()) {
        result.push_back(processes[currentProcess]);
        currentTime += timeSlice;
        currentProcess = (currentProcess + 1) % processes.size();
    }

    return result;
}

int main() {
    vector<int> processes = {3, 1, 2, 4};
    int timeSlice = 2;
    vector<int> result = simulateScheduler(processes, timeSlice);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
