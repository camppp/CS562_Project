#include <iostream>
#include <string>

class BankAccount {
public:
    BankAccount(const std::string& name, double initialBalance) {
        this->name = name;
        this->balance = initialBalance;
    }

    void deposit(double amount) {
        this->balance += amount;
    }

    bool withdraw(double amount) {
        if (this->balance >= amount) {
            this->balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    double getBalance() const {
        return this->balance;
    }

private:
    std::string name;
    double balance;
};

int main() {
    BankAccount account("John Doe", 1000.0);

    account.deposit(500.0);
    std::cout << "Account balance after deposit: " << account.getBalance() << std::endl;

    account.withdraw(200.0);
    std::cout << "Account balance after withdrawal: " << account.getBalance() << std::endl;

    account.deposit(300.0);
    std::cout << "Account balance after another deposit: " << account.getBalance() << std::endl;

    return 0;
}
