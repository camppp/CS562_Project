#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> customSampler(vector<tuple<string, int, bool>> playlist, int maxDuration) {
    // Sort the playlist by duration in ascending order
    sort(playlist.begin(), playlist.end(), [](const tuple<string, int, bool>& a, const tuple<string, int, bool>& b) {
        return a.second < b.second;
    });

    // Initialize the output vector
    vector<string> output;

    // Iterate over the playlist and add songs to the output vector
    for (const auto& song : playlist) {
        // If the song is a favorite, add it to the output vector
        if (song.third) {
            output.push_back(song.first);
        }

        // If the song duration is less than the maximum duration, add it to the output vector
        if (song.second < maxDuration) {
            output.push_back(song.first);
        }

        // If the output vector has reached the maximum size, stop adding songs
        if (output.size() == maxDuration) {
            break;
        }
    }

    return output;
}

int main() {
    vector<tuple<string, int, bool>> playlist = {
        {"Song1", 3, false},
        {"Song2", 4, true},
        {"Song3", 5, false},
        {"Song4", 2, false},
        {"Song5", 3, true}
    };

    int maxDuration = 10;

    vector<string> output = customSampler(playlist, maxDuration);

    for (const auto& song : output) {
        cout << song << endl;
    }

    return 0;
}
