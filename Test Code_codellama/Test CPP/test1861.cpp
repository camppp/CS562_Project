#include <iostream>
#include <map>
#include <string>

class VendingMachine {
private:
    std::map<int, std::pair<std::string, double>> items; // itemID -> (itemName, itemPrice)
    double balance;

public:
    // Constructor to initialize the available items
    VendingMachine(std::map<int, std::pair<std::string, double>> availableItems) {
        items = availableItems;
        balance = 0.0;
    }

    // Method to insert a coin into the vending machine
    void insertCoin(double coinValue) {
        balance += coinValue;
    }

    // Method to select an item for purchase
    void selectItem(int itemID) {
        if (items.find(itemID) != items.end()) {
            if (balance >= items[itemID].second) {
                std::cout << "Dispensing item: " << items[itemID].first << std::endl;
                returnChange();
            } else {
                std::cout << "Insufficient balance to purchase " << items[itemID].first << std::endl;
            }
        } else {
            std::cout << "Invalid item selection" << std::endl;
        }
    }

    // Method to return any remaining balance to the user
    void returnChange() {
        std::cout << "Returning change: " << balance << std::endl;
        balance = 0.0;
    }

    // Method to get the current balance of the vending machine
    double getBalance() {
        return balance;
    }

    // Method to get the list of available items in the vending machine
    std::map<int, std::pair<std::string, double>> getAvailableItems() {
        return items;
    }

    // Method to get the price of an item with a given ID
    double getItemPrice(int itemID) {
        if (items.find(itemID) != items.end()) {
            return items[itemID].second;
        } else {
            return 0.0;
        }
    }
};

int main() {
    std::map<int, std::pair<std::string, double>> availableItems = {
        {1, {"Soda", 1.50}},
        {2, {"Chips", 1.25}},
        {3, {"Candy", 1.00}}
    };

    VendingMachine vendingMachine(availableItems);
    vendingMachine.insertCoin(1.0);
    vendingMachine.selectItem(2);
    vendingMachine.insertCoin(0.5);
    vendingMachine.selectItem(1);

    std::cout << "Current balance: " << vendingMachine.getBalance() << std::endl;
    std::cout << "Available items: " << vendingMachine.getAvailableItems() << std::endl;
    std::cout << "Item price: " << vendingMachine.getItemPrice(1) << std::endl;

    return 0;
}
