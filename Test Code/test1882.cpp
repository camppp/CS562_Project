#include <iostream>
#include <vector>
#include <unordered_map>

std::string findWinner(const std::vector<std::string>& votes) {
    std::unordered_map<std::string, int> count;
    for (const auto& vote : votes) {
        count[vote]++;
    }
    int maxVotes = 0;
    std::string winner;
    for (const auto& pair : count) {
        if (pair.second > maxVotes) {
            maxVotes = pair.second;
            winner = pair.first;
        }
    }
    int numWinners = 0;
    for (const auto& pair : count) {
        if (pair.second == maxVotes) {
            numWinners++;
        }
    }
    if (numWinners == 1) {
        return winner;
    } else {
        return "No winner";
    }
}

int main() {
    std::vector<std::string> votes = {"Alice", "Bob", "Alice", "Charlie", "Bob", "Alice"};
    std::cout << "Winner: " << findWinner(votes) << std::endl;
    return 0;
}
