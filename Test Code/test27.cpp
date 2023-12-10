#include <iostream>

class BankAccount {
private:
    double balance;
    int totalTransactions;

public:
    BankAccount(double initialBalance) : balance(initialBalance), totalTransactions(0) {}

    void deposit(double amount) {
        balance += amount;
        totalTransactions++;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            totalTransactions++;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }

    int getTotalTransactions() const {
        return totalTransactions;
    }
};

int main() {
    BankAccount account(1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);
    std::cout << "Current Balance: " << account.getBalance() << std::endl;
    std::cout << "Total Transactions: " << account.getTotalTransactions() << std::endl;
    return 0;
}
