#include <string>
#include <iostream>

std::string finalPosition(std::string commands) {
    int x = 0, y = 0, i = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (char c : commands) {
        if (c == 'R') {
            i = (i + 1) % 4;
        } else if (c == 'L') {
            i = (i + 3) % 4;
        } else {
            x += dx[i];
            y += dy[i];
        }
    }

    return std::to_string(x) + " " + std::to_string(y);
}

int main() {
    std::cout << finalPosition("FFRFF") << std::endl;  // Output: "2 2"
    return 0;
}
