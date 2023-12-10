#include <string>
#include <vector>
#include <algorithm>

struct SeatInfo {
    int row;
    int column;
    int seatId;
};

SeatInfo getSeatInfo(const std::string& boardingPass) {
    int row = 0;
    int column = 0;
    for (char c : boardingPass) {
        if (c == 'F') {
            row <<= 1;
        } else if (c == 'B') {
            row = (row << 1) | 1;
        } else if (c == 'L') {
            column <<= 1;
        } else if (c == 'R') {
            column = (column << 1) | 1;
        }
    }
    return {row, column, row * 8 + column};
}

int findMissingSeat(const std::vector<std::string>& boardingPasses) {
    std::vector<int> seatIds;
    for (const auto& pass : boardingPasses) {
        SeatInfo info = getSeatInfo(pass);
        seatIds.push_back(info.seatId);
    }
    std::sort(seatIds.begin(), seatIds.end());
    for (size_t i = 1; i < seatIds.size(); ++i) {
        if (seatIds[i] - seatIds[i - 1] > 1) {
            return seatIds[i] - 1;
        }
    }
    return -1;  // No missing seat found
}
