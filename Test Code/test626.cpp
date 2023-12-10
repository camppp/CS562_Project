#include <iostream>
#include <unordered_map>
using namespace std;

int longestUniquePlaylist(int playlist[], int n) {
    unordered_map<int, int> songIndex;
    int maxLength = 0, start = 0;

    for (int end = 0; end < n; end++) {
        if (songIndex.find(playlist[end]) != songIndex.end()) {
            start = max(start, songIndex[playlist[end]] + 1);
        }
        songIndex[playlist[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
}

int main() {
    int n = 6;
    int playlist[] = {1, 2, 3, 2, 5, 6};
    cout << longestUniquePlaylist(playlist, n) << endl;  // Output: 5
    return 0;
}
