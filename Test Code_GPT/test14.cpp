#include <iostream>
#include <string>

class Product {
public:
    // Constructor
    Product(const std::string& productName, int initialQuantity)
        : name(productName), quantity(initialQuantity) {}

    // Method to add stock
    void addStock(int amount) {
        if (amount > 0) {
            quantity += amount;
            std::cout << "Added " << amount << " units of " << name << " to the stock." << std::endl;
        } else {
            std::cerr << "Error: Invalid amount to add. Amount must be greater than 0." << std::endl;
        }
    }

    // Method to sell products
    void sell(int amount) {
        if (amount > 0) {
            if (quantity >= amount) {
                quantity -= amount;
                std::cout << "Sold " << amount << " units of " << name << "." << std::endl;
            } else {
                std::cout << "Error: Insufficient stock. Cannot sell " << amount << " units of " << name
                          << ". Available stock: " << quantity << " units." << std::endl;
            }
        } else {
            std::cerr << "Error: Invalid amount to sell. Amount must be greater than 0." << std::endl;
        }
    }

    // Getter method for quantity
    int getQuantity() const {
        return quantity;
    }

private:
    std::string name;
    int quantity;
};

int main() {
    // Example usage
    Product laptop("Laptop", 10);
    Product smartphone("Smartphone", 20);

    // Add stock
    laptop.addStock(5);
    smartphone.addStock(10);

    // Sell products
    laptop.sell(3);
    smartphone.sell(15); // This will print an error message due to insufficient stock

    // Display remaining stock
    std::cout << "Remaining stock of Laptop: " << laptop.getQuantity() << " units." << std::endl;
    std::cout << "Remaining stock of Smartphone: " << smartphone.getQuantity() << " units." << std::endl;

    return 0;
}
