#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class RoomInfo {
public:
    int integer_;
    // Other members and methods
};

void findAndPrintRoomInteger(const std::vector<RoomInfo>& container) {
    auto ite = std::find_if(container.begin(), container.end(), std::bind(&RoomInfo::integer_, std::placeholders::_1) == 1);
    if (ite != container.end()) {
        std::cout << ite->integer_ << std::endl;
    } else {
        std::cout << "Room with integer value 1 not found" << std::endl;
    }
}

int main() {
    std::vector<RoomInfo> rooms = {{1}, {2}, {3}, {1}, {4}};
    findAndPrintRoomInteger(rooms); // Output: 1
    return 0;
}
