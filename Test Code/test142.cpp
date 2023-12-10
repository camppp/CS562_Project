#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    double balance;

public:
    BankAccount(const std::string& name, double initialBalance) : accountHolderName(name), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account("John Doe", 1000.0);
    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    account.deposit(500.0);
    std::cout << "Balance after deposit: " << account.getBalance() << std::endl;

    if (account.withdraw(200.0)) {
        std::cout << "Balance after withdrawal: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Insufficient funds for withdrawal" << std::endl;
    }

    if (account.withdraw(2000.0)) {
        std::cout << "Balance after withdrawal: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Insufficient funds for withdrawal" << std::endl;
    }

    return 0;
}
