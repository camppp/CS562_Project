#include <iostream>

class BankAccount {
private:
    double balance;
    const double minBalance = 100;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance - amount >= minBalance) {
            balance -= amount;
            return true;
        } else {
            std::cout << "Withdrawal rejected. Insufficient balance." << std::endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(500);  // Create an account with initial balance of 500
    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    account.deposit(300);  // Deposit 300
    std::cout << "Balance after deposit: " << account.getBalance() << std::endl;

    if (account.withdraw(400)) {  // Withdraw 400
        std::cout << "Balance after withdrawal: " << account.getBalance() << std::endl;
    }

    if (account.withdraw(600)) {  // Attempt to withdraw 600 (rejected)
        std::cout << "Balance after withdrawal: " << account.getBalance() << std::endl;
    }

    return 0;
}
