#include <iostream>

class BankAccount {
public:
    BankAccount(int initialBalance) {
        balance = initialBalance;
        transactionCount = 0;
    }

    void deposit(int amount) {
        balance += amount;
        transactionCount++;
    }

    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionCount++;
        }
    }

    int getBalance() {
        return balance;
    }

    int getTransactionCount() {
        return transactionCount;
    }

private:
    int balance;
    int transactionCount;
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
