#include <iostream>

class BankAccount {
public:
    BankAccount(std::string name) : name(name), balance(0) {}

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    int getBalance() {
        return balance;
    }

    void transfer(BankAccount& to, int amount) {
        if (balance >= amount) {
            balance -= amount;
            to.deposit(amount);
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

private:
    std::string name;
    int balance;
};
