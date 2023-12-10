#include <iostream>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, std::string accountHolderName, double balance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}

    void setAccountNumber(int accountNumber) {
        this->accountNumber = accountNumber;
    }

    void setAccountHolderName(std::string accountHolderName) {
        this->accountHolderName = accountHolderName;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds" << std::endl;
        } else {
            balance -= amount;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account1(1234, "John Doe", 1000);
    BankAccount account2(5678, "Jane Smith", 2000);

    account1.deposit(500);
    account2.withdraw(1500);

    std::cout << "Account 1: " << account1.getBalance() << std::endl;
    std::cout << "Account 2: " << account2.getBalance() << std::endl;

    return 0;
}
