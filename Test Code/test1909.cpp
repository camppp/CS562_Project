#include <iostream>
#include <map>

enum class Direction { NE, NW, SE, SW }; // Define the enum class for directions

class Room {
private:
    std::map<Direction, Room*> portals; // Map to store portal destinations

public:
    void SetPortalDest(Direction portalPos, Room* dest) {
        portals[portalPos] = dest; // Set the destination room for the specified portal position
    }

    Room* GetPortalDestination(Direction portalPos) {
        if (portals.find(portalPos) != portals.end()) {
            return portals[portalPos]; // Return the destination room for the specified portal position
        }
        else {
            return nullptr; // Return nullptr if the portal destination is not set
        }
    }
};

int main() {
    Room room1, room2;
    room1.SetPortalDest(Direction::NE, &room2); // Set a portal from room1 to room2 in the northeast direction

    // Example usage: moving through the portal
    Room* currentRoom = &room1;
    Direction moveDirection = Direction::NE;
    Room* nextRoom = currentRoom->GetPortalDestination(moveDirection);
    if (nextRoom != nullptr) {
        currentRoom = nextRoom; // Move to the next room through the portal
    }
    else {
        std::cout << "No portal in the specified direction." << std::endl;
    }

    return 0;
}
