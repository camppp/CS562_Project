#include <iostream>
#include <vector>
#include <string>

std::vector<int> processCards(std::string line) {
    int queens[]  = { 0, 0, 0, 0 };
    int jacks[]   = { 0, 0, 0, 0 };
    bool stop[]   = { false, false, false, false };
    std::string table = "SHDC";

    for (int i = 0; i < line.size(); i += 3) {
        char rank = line[i];
        int suit;
        for (int j = 0; j < 4; ++j) { 
            if (table[j] == line[i + 1]) { suit = j; }
        }
        switch(rank) {
            case 'Q':
                queens[suit]++;
                break;
            case 'J':
                jacks[suit]++;
                break;
            case 'S':
                stop[0] = true;
                break;
            case 'H':
                stop[1] = true;
                break;
            case 'D':
                stop[2] = true;
                break;
            case 'C':
                stop[3] = true;
                break;
            default:
                break;
        }
    }

    std::vector<int> result;
    for (int i = 0; i < 4; ++i) {
        result.push_back(queens[i]);
    }
    return result;
}

int main() {
    std::string line = "ASQS2HKS3D";
    std::vector<int> result = processCards(line);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    return 0;
}
