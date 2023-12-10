#include <iostream>

class BankAccount {
private:
    double balance;
    int transactionCount;

public:
    BankAccount(double initialBalance) : balance(initialBalance), transactionCount(0) {}

    void deposit(double amount) {
        balance += amount;
        transactionCount++;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionCount++;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    int getTransactionCount() const {
        return transactionCount;
    }
};

int main() {
    BankAccount account(1000);
    account.deposit(500);
    account.withdraw(200);
    account.deposit(300);
    account.withdraw(100);

    std::cout << "Final Balance: " << account.getBalance() << std::endl;
    std::cout << "Total Transactions: " << account.getTransactionCount() << std::endl;

    return 0;
}
