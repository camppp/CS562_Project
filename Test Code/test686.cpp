#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    double checkBalance() {
        return balance;
    }

    void transfer(BankAccount& recipient, double amount) {
        if (amount <= balance) {
            balance -= amount;
            recipient.deposit(amount);
        } else {
            std::cout << "Insufficient funds for transfer" << std::endl;
        }
    }
};

int main() {
    BankAccount account1(1000);
    BankAccount account2(500);

    std::cout << "Initial balances:" << std::endl;
    std::cout << "Account 1: " << account1.checkBalance() << std::endl;
    std::cout << "Account 2: " << account2.checkBalance() << std::endl;

    account1.deposit(500);
    account2.withdraw(200);
    account1.transfer(account2, 300);

    std::cout << "Final balances:" << std::endl;
    std::cout << "Account 1: " << account1.checkBalance() << std::endl;
    std::cout << "Account 2: " << account2.checkBalance() << std::endl;

    return 0;
}
