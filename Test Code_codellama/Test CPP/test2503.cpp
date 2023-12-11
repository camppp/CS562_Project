#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("verification_times.txt");
    vector<string> stage_names = {"TimeOfEqCheck", "TimeOfInvValidate", "TimeOfInvProof", "TimeOfInvSyn", "TimeOfInvSynEnhance"};
    vector<double> stage_times;

    // Read the time measurements from the file
    while (file.good()) {
        string line;
        getline(file, line);
        if (line.empty()) {
            continue;
        }
        double time = stod(line);
        stage_times.push_back(time);
    }

    // Calculate the average time taken for each stage
    vector<double> average_times(stage_names.size());
    for (int i = 0; i < stage_names.size(); i++) {
        average_times[i] = accumulate(stage_times.begin() + i, stage_times.begin() + i + 1, 0.0) / stage_times.size();
    }

    // Identify the stage that took the longest time
    int longest_stage = 0;
    double longest_time = average_times[0];
    for (int i = 1; i < stage_names.size(); i++) {
        if (average_times[i] > longest_time) {
            longest_time = average_times[i];
            longest_stage = i;
        }
    }

    // Print the results
    cout << "Average time taken for each stage: ";
    for (int i = 0; i < stage_names.size(); i++) {
        cout << stage_names[i] << ": " << average_times[i] << " ms" << endl;
    }
    cout << "Longest stage: " << stage_names[longest_stage] << " (" << longest_time << " ms)" << endl;

    return 0;
}
