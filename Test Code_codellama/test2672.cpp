#include <iostream>
#include <string>
#include <vector>

class Room {
public:
    Room(std::string name, std::string description, std::vector<std::string> exits) {
        this->name = name;
        this->description = description;
        this->exits = exits;
    }

    std::string get_name() {
        return this->name;
    }

    std::string get_description() {
        return this->description;
    }

    std::vector<std::string> get_exits() {
        return this->exits;
    }

private:
    std::string name;
    std::string description;
    std::vector<std::string> exits;
};

int main() {
    // Create a sample room object
    Room room("Living Room", "You are in a cozy living room with a couch and a TV.", {"Kitchen", "Bedroom"});

    // Access the attributes of the room
    std::cout << "Name: " << room.get_name() << std::endl;
    std::cout << "Description: " << room.get_description() << std::endl;
    std::cout << "Exits: ";
    for (const auto& exit : room.get_exits()) {
        std::cout << exit << " ";
    }
    std::cout << std::endl;

    return 0;
}
