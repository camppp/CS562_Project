#include <iostream>
#include "commands.h"

void performCommand(Command cmd) {
    switch (cmd) {
        case Command::MOVE:
            std::cout << "Player moves to a new location." << std::endl;
            break;
        case Command::ATTACK:
            std::cout << "Player attacks the enemy." << std::endl;
            break;
        case Command::USE_ITEM:
            std::cout << "Player uses an item." << std::endl;
            break;
        case Command::UNKNOWN:
            std::cout << "Unknown command." << std::endl;
            break;
    }
}
