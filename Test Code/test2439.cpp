#include <iostream>

class BankAccount {
private:
    int balance;

public:
    BankAccount() : balance(0) {}

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount" << std::endl;
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << std::endl;
        } else {
            std::cout << "Insufficient funds or invalid withdrawal amount" << std::endl;
        }
    }

    int get_balance() {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(100);
    account.withdraw(50);
    std::cout << "Current Balance: " << account.get_balance() << std::endl;
    account.withdraw(70);
    std::cout << "Current Balance: " << account.get_balance() << std::endl;
    return 0;
}
