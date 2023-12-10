#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& holder) : accountHolder(holder), balance(0) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;  // Insufficient funds
    }

    double getBalance() const {
        return balance;
    }

    void transfer(BankAccount& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            std::cout << amount << " transferred to " << recipient.accountHolder << std::endl;
        } else {
            std::cout << "Insufficient funds for transfer" << std::endl;
        }
    }
};

int main() {
    BankAccount alice("Alice");
    BankAccount bob("Bob");

    alice.deposit(1000);
    bob.deposit(500);

    alice.transfer(bob, 300);

    std::cout << "Alice's balance: " << alice.getBalance() << std::endl;
    std::cout << "Bob's balance: " << bob.getBalance() << std::endl;

    return 0;
}
