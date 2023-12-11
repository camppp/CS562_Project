#include <iostream>
#include <vector>

// Enum class to represent the directions
enum class Directions {
    NE,
    NW,
    SE,
    SW
};

// Class to represent a room
class Room {
public:
    // Constructor to initialize the room
    Room(int id, std::string name, std::vector<Portal> portals) : id_(id), name_(name), portals_(portals) {}

    // Method to set the destination of a portal in a specific direction
    void SetPortalDest(Directions direction, Room* destination) {
        // Find the portal in the specified direction
        auto portal = std::find_if(portals_.begin(), portals_.end(), [direction](const Portal& portal) {
            return portal.direction == direction;
        });

        // Set the destination of the portal
        portal->destination = destination;
    }

private:
    // Unique identifier for the room
    int id_;

    // Name of the room
    std::string name_;

    // Vector of portals in the room
    std::vector<Portal> portals_;
};

// Class to represent a portal
class Portal {
public:
    // Constructor to initialize the portal
    Portal(Directions direction, Room* destination) : direction(direction), destination(destination) {}

    // Direction of the portal
    Directions direction;

    // Destination room of the portal
    Room* destination;
};

int main() {
    // Create a room with a portal in the northeast direction
    Room* room1 = new Room(1, "Room 1", { Portal(Directions::NE, new Room(2, "Room 2")) });

    // Create a room with a portal in the southwest direction
    Room* room2 = new Room(2, "Room 2", { Portal(Directions::SW, new Room(1, "Room 1")) });

    // Set the destination of the portal in the northeast direction of room 1 to room 2
    room1->SetPortalDest(Directions::NE, room2);

    // Set the destination of the portal in the southwest direction of room 2 to room 1
    room2->SetPortalDest(Directions::SW, room1);

    // Print the portals of each room
    std::cout << "Portals of Room 1: ";
    for (const auto& portal : room1->portals_) {
        std::cout << portal.direction << " -> " << portal.destination->name_ << std::endl;
    }

    std::cout << "Portals of Room 2: ";
    for (const auto& portal : room2->portals_) {
        std::cout << portal.direction << " -> " << portal.destination->name_ << std::endl;
    }

    return 0;
}
