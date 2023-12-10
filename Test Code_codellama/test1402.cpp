#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class RoomInfo {
public:
    int integer_;
    // Other members and methods
};

void findAndPrintRoomInteger(const std::vector<RoomInfo>& container) {
    auto predicate = std::bind(std::equal_to<int>(), std::placeholders::_1.integer_, 1);
    auto it = std::find_if(container.begin(), container.end(), predicate);
    if (it != container.end()) {
        std::cout << it->integer_ << std::endl;
    }
}

int main() {
    std::vector<RoomInfo> container = {
        {1}, {2}, {3}, {4}, {5}
    };
    findAndPrintRoomInteger(container);
    return 0;
}
