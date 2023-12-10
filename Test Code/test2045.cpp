#include <iostream>

class BankAccount {
private:
    double balance;

public:
    // Default constructor
    BankAccount() : balance(0) {}

    // Parameterized constructor
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Copy constructor
    BankAccount(const BankAccount &other) : balance(other.balance) {}

    // Assignment operator overload
    BankAccount &operator=(const BankAccount &other) {
        if (this != &other) {
            balance = other.balance;
        }
        return *this;
    }

    // Destructor
    ~BankAccount() {
        std::cout << "Account closed" << std::endl;
    }

    // Method to deposit funds
    void deposit(double amount) {
        balance += amount;
    }

    // Method to withdraw funds
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    // Method to retrieve current balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    // Test the BankAccount class
    BankAccount account1; // Default constructor
    std::cout << "Initial balance: " << account1.getBalance() << std::endl;

    account1.deposit(1000); // Deposit funds
    std::cout << "Balance after deposit: " << account1.getBalance() << std::endl;

    account1.withdraw(500); // Withdraw funds
    std::cout << "Balance after withdrawal: " << account1.getBalance() << std::endl;

    BankAccount account2 = account1; // Copy constructor
    std::cout << "Balance of copied account: " << account2.getBalance() << std::endl;

    BankAccount account3;
    account3 = account1; // Assignment operator overload
    std::cout << "Balance of assigned account: " << account3.getBalance() << std::endl;

    return 0;
}
