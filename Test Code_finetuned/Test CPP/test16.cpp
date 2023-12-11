#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    int quantity;

public:
    Product(std::string name, int quantity) : name(name), quantity(quantity) {}

    void addStock(int amount) {
        quantity += amount;
    }

    void sell(int amount) {
        if (amount > quantity) {
            std::cout << "Sale cannot be completed due to insufficient stock." << std::endl;
        } else {
            quantity -= amount;
        }
    }

    std::string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }
};

int main() {
    Product product1("Apple", 10);
    std::cout << "Product: " << product1.getName() << ", Quantity: " << product1.getQuantity() << std::endl;

    product1.addStock(5);
    std::cout << "Product: " << product1.getName() << ", Quantity: " << product1.getQuantity() << std::endl;

    product1.sell(15);
    std::cout << "Product: " << product1.getName() << ", Quantity: " << product1.getQuantity() << std::endl;

    product1.sell(5);
    std::cout << "Product: " << product1.getName() << ", Quantity: " << product1.getQuantity() << std::endl;

    return 0;
}