#include <iostream>

class BankAccount {
private:
    double balance;
    int totalTransactions;

public:
    // Constructor
    BankAccount(double initialBalance) : balance(initialBalance), totalTransactions(0) {}

    // Deposit funds
    void deposit(double amount) {
        balance += amount;
        totalTransactions++;
    }

    // Withdraw funds
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            totalTransactions++;
        } else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }

    // Get current balance
    double getBalance() const {
        return balance;
    }

    // Get total number of transactions
    int getTotalTransactions() const {
        return totalTransactions;
    }
};

int main() {
    // Example usage
    BankAccount account(1000.0);
    
    account.deposit(500.0);
    account.withdraw(200.0);
    
    std::cout << "Current Balance: " << account.getBalance() << std::endl;
    std::cout << "Total Transactions: " << account.getTotalTransactions() << std::endl;

    return 0;
}
