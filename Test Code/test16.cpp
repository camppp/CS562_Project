//-----------------------------------------------------------------------------
// Copyright (c) 2018 <NAME>
//
// https://github.com/bebuch/disposer_module
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>

class Product {
public:
    std::string name;
    int quantity;

    void addStock(int amount) {
        quantity += amount;
    }

    void sell(int amount) {
        if (amount > quantity) {
            std::cout << "Insufficient stock to complete the sale." << std::endl;
        } else {
            quantity -= amount;
        }
    }
};

int main() {
    Product laptop;
    laptop.name = "Laptop";
    laptop.quantity = 10;

    std::cout << "Initial quantity of " << laptop.name << ": " << laptop.quantity << std::endl;

    laptop.addStock(5);
    std::cout << "Quantity after adding stock: " << laptop.quantity << std::endl;

    laptop.sell(3);
    std::cout << "Quantity after selling 3 units: " << laptop.quantity << std::endl;

    laptop.sell(10); // Attempt to sell more than available
    return 0;
}
