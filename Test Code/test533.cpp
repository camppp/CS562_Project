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
        for (size_t i = 0; i < menuItems.size(); ++i) {
            std::cout << i + 1 << ". ";
            menuItems[i].displayText();
        }
    }

    int getUserChoice() {
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        while (choice < 1 || choice > static_cast<int>(menuItems.size())) {
            std::cout << "Invalid choice. Please enter a valid option: ";
            std::cin >> choice;
        }
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
