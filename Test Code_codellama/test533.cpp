#include <iostream>
#include <string>
#include <vector>

class MenuItem {
public:
    std::string text;

    void displayText() {
        std::cout << text << std::endl;
    }
};

class Menu {
public:
    std::vector<MenuItem> menuItems;

    void addMenuItem(const std::string& text) {
        MenuItem newItem;
        newItem.text = text;
        menuItems.push_back(newItem);
    }

    void displayMenu() {
        for (const auto& item : menuItems) {
            item.displayText();
        }
    }

    int getUserChoice() {
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        return choice;
    }
};

int main() {
    Menu menu;
    menu.addMenuItem("Option 1");
    menu.addMenuItem("Option 2");
    menu.displayMenu();
    int userChoice = menu.getUserChoice();
    std::cout << "You chose option " << userChoice << std::endl;
    return 0;
}
