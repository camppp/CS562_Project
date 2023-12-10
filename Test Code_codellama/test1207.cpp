#include <iostream>
#include <map>
#include <string>

class Inventory {
private:
    std::map<int, std::pair<std::string, int, double>> items; // Map to store items with unique identifier as key

public:
    void addItem(int id, const std::string& name, int quantity, double price) {
        if (items.find(id) != items.end()) {
            items[id].second += quantity; // Update quantity if item already exists
        } else {
            items[id] = std::make_pair(name, quantity, price); // Add new item to inventory
        }
    }

    void removeItem(int id, int quantity) {
        if (items.find(id) != items.end()) {
            if (items[id].second <= quantity) {
                items.erase(id); // Remove item if quantity to be removed exceeds available quantity
            } else {
                items[id].second -= quantity; // Update quantity
            }
        }
    }

    void displayInventory() {
        std::cout << "Inventory:\n";
        for (const auto& item : items) {
            std::cout << "ID: " << item.first << ", Name: " << item.second.first
                      << ", Quantity: " << item.second.second << ", Price: $" << item.second.third << std::endl;
        }
    }
};

int main() {
    Inventory storeInventory;

    // Add items to inventory
    storeInventory.addItem(1, "Shirt", 50, 25.99);
    storeInventory.addItem(2, "Pants", 30, 39.99);
    storeInventory.addItem(1, "Shirt", 20, 25.99); // Update quantity of existing item

    // Display inventory
    storeInventory.displayInventory();

    // Remove items from inventory
    storeInventory.removeItem(1, 30); // Remove 30 shirts
    storeInventory.displayInventory();

    return 0;
}
