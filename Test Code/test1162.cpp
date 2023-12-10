#include <iostream>
#include <map>

class Inventory {
private:
    struct Item {
        std::string name;
        int quantity;
        double price;
    };

    std::map<int, Item> items;

public:
    void add_item(int id, const std::string& name, int quantity, double price) {
        items[id] = {name, quantity, price};
    }

    void remove_item(int id) {
        items.erase(id);
    }

    void display_inventory() {
        std::cout << "Inventory:\n";
        for (const auto& [id, item] : items) {
            std::cout << "ID: " << id << ", Name: " << item.name << ", Quantity: " << item.quantity << ", Price: " << item.price << '\n';
        }
    }
};

int main() {
    Inventory storeInventory;

    storeInventory.add_item(1, "Shirt", 50, 25.99);
    storeInventory.add_item(2, "Pants", 40, 35.50);
    storeInventory.display_inventory();

    storeInventory.remove_item(1);
    storeInventory.display_inventory();

    return 0;
}
