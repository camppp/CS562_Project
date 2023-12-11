#include <iostream>

class BankAccount {
private:
    double balance;
    int totalTransactions;

public:
    // Constructor
    BankAccount(double initialBalance) : balance(initialBalance), totalTransactions(0) {}

    // Deposit method
    void deposit(double amount) {
        balance += amount;
        totalTransactions++;
    }

    // Withdraw method
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            totalTransactions++;
            return true;
        }
        return false;
    }

    // Get balance method
    double getBalance() const {
        return balance;
    }

    // Get total transactions method
    int getTotalTransactions() const {
        return totalTransactions;
    }
};

int main() {
    BankAccount account(1000);
    account.deposit(500);
    account.withdraw(200);
    std::cout << "Current balance: " << account.getBalance() << std::endl;
    std::cout << "Total transactions: " << account.getTotalTransactions() << std::endl;
    return 0;
}