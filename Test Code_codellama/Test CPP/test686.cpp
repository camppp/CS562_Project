#include <iostream>
#include <string>

class BankAccount {
public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }

    void transfer(BankAccount& otherAccount, double amount) {
        if (balance >= amount) {
            balance -= amount;
            otherAccount.deposit(amount);
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

private:
    double balance;
};
