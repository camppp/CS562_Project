#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, const std::string& accHolder) : accountNumber(accNum), accountHolderName(accHolder), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Error: Insufficient funds for withdrawal." << std::endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    const std::string& getAccountHolderName() const {
        return accountHolderName;
    }
};

int main() {
    std::vector<BankAccount> accounts;

    // Create accounts
    BankAccount acc1(1001, "Alice");
    BankAccount acc2(1002, "Bob");
    accounts.push_back(acc1);
    accounts.push_back(acc2);

    // Perform transactions
    acc1.deposit(500);
    acc2.deposit(1000);
    acc1.withdraw(200);
    acc2.withdraw(500);
    acc1.withdraw(400); // This should display an error message

    // Display account details
    for (const auto& acc : accounts) {
        std::cout << "Account Number: " << acc.getAccountNumber() << std::endl;
        std::cout << "Account Holder: " << acc.getAccountHolderName() << std::endl;
        std::cout << "Current Balance: " << acc.getBalance() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
