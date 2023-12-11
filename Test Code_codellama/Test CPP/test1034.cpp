#include <iostream>
#include <string>
#include <map>
#include <vector>

class Room {
public:
    Room(std::string name, std::string description, std::map<std::string, Room*> exits, std::vector<std::string> items) :
        name(name), description(description), exits(exits), items(items) {}

    void add_exit(std::string direction, Room* room) {
        exits[direction] = room;
    }

    void remove_exit(std::string direction) {
        exits.erase(direction);
    }

    void add_item(std::string item) {
        items.push_back(item);
    }

    void remove_item(std::string item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    std::string get_name() {
        return name;
    }

    std::string get_description() {
        return description;
    }

    std::map<std::string, Room*> get_exits() {
        return exits;
    }

    std::vector<std::string> get_items() {
        return items;
    }

private:
    std::string name;
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<std::string> items;
};

class Player {
public:
    Player(Room* current_room) : current_room(current_room) {}

    void move_to_room(Room* room) {
        current_room = room;
    }

    void pick_up_item(std::string item) {
        current_room->remove_item(item);
        inventory.push_back(item);
    }

    void drop_item(std::string item) {
        inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
        current_room->add_item(item);
    }

    Room* get_current_room() {
        return current_room;
    }

    std::vector<std::string> get_inventory() {
        return inventory;
    }

private:
    Room* current_room;
    std::vector<std::string> inventory;
};

int main() {
    // Create the rooms
    Room* room1 = new Room("Room 1", "You are in a dimly lit room with a single door.", {{"north", room2}}, {"key"});
    Room* room2 = new Room("Room 2", "You are in a large, open room with a table in the center.", {{"south", room1}}, {"book"});

    // Create the player
    Player* player = new Player(room1);

    // Start the game
    while (true) {
        std::cout << "You are in " << player->get_current_room()->get_name() << "." << std::endl;
        std::cout << player->get_current_room()->get_description() << std::endl;
        std::cout << "Exits: ";
        for (auto& exit : player->get_current_room()->get_exits()) {
            std::cout << exit.first << " ";
        }
        std::cout << std::endl;
        std::cout << "Items: ";
        for (auto& item : player->get_current_room()->get_items()) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
        std::cout << "Inventory: ";
        for (auto& item : player->get_inventory()) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
        std::cout << "What would you like to do? (type 'move' to move, 'pick' to pick up an item, 'drop' to drop an item, or 'quit' to quit)" << std::endl;
        std::string input;
        std::cin >> input;
        if (input == "move") {
            std::cout << "Which direction would you like to move? (type 'north', 'south', 'east', or 'west')" << std::endl;
            std::string direction;
            std::cin >> direction;
            if (player->get_current_room()->get_exits().find(direction) != player->get_current_room()->get_exits().end()) {
                player->move_to_room(player->get_current_room()->get_exits()[direction]);
            } else {
                std::cout << "You can't move that way." << std::endl;
            }
        } else if (input == "pick") {
            std::cout << "Which item would you like to pick up? (type the name of the item)" << std::endl;
            std::string item;
            std::cin >> item;
            if (player->get_current_room()->get_items().find(item) != player->get_current_room()->get_items().end()) {
                player->pick_up_item(item);
            } else {
                std::cout << "You can't find that item." << std::endl;
            }
        } else if (input == "drop") {
            std::cout << "Which item would you like to drop? (type the name of the item)" << std::endl;
            std::string item;
            std::cin >> item;
            if (player->get_inventory().find(item) != player->get_inventory().end()) {
                player->drop_item(item);
            } else {
                std::cout << "You don't have that item." << std::endl;
            }
        } else if (input == "quit") {
            break;
        } else {
            std::cout << "I don't understand that command." << std::endl;
        }
    }

    return 0;
}
