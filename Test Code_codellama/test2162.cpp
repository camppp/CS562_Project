#include <iostream>
#include <vector>

using namespace std;

void publish_landmarks(Publisher& pubLandMarks, const vector<tuple<int, int>>& landmarks) {
    // Format the landmarks into a message
    string message = "";
    for (const auto& landmark : landmarks) {
        message += "(" + to_string(get<0>(landmark)) + ", " + to_string(get<1>(landmark)) + ") ";
    }

    // Publish the message
    pubLandMarks.publish(message);
}
