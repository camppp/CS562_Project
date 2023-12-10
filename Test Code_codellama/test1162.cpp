#include <iostream>
#include <string>
#include <map>

class Inventory {
private:
    std::map<int, std::string> items;
    std::map<int, int> quantities;
    std::map<int, double> prices;

public:
    void add_item(int id, std::string name, int quantity, double price) {
        items[id] = name;
        quantities[id] = quantity;
        prices[id] = price;
    }

    void remove_item(int id) {
        items.erase(id);
        quantities.erase(id);
        prices.erase(id);
    }

    void display_inventory() {
        for (const auto& item : items) {
            std::cout << "Item ID: " << item.first << std::endl;
            std::cout << "Item Name: " << item.second << std::endl;
            std::cout << "Quantity: " << quantities[item.first] << std::endl;
            std::cout << "Price: " << prices[item.first] << std::endl;
        }
    }
};
