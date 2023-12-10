#include <iostream>
#include <vector>

class BankAccount {
public:
    BankAccount(std::string accountNumber, double initialBalance) 
        : accountNumber_(std::move(accountNumber)), balance_(initialBalance) {
        // Constructor implementation
    }

    void deposit(double amount) {
        balance_ += amount;
        transactionHistory_.push_back("Deposit: +" + std::to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= balance_) {
            balance_ -= amount;
            transactionHistory_.push_back("Withdrawal: -" + std::to_string(amount));
        } else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }

    void transfer(BankAccount& recipient, double amount) {
        if (amount <= balance_) {
            balance_ -= amount;
            recipient.balance_ += amount;
            transactionHistory_.push_back("Transfer: -" + std::to_string(amount) + " to " + recipient.accountNumber_);
            recipient.transactionHistory_.push_back("Transfer: +" + std::to_string(amount) + " from " + accountNumber_);
        } else {
            std::cout << "Insufficient funds for transfer." << std::endl;
        }
    }

    double getBalance() const {
        return balance_;
    }

    std::vector<std::string> getTransactionHistory() const {
        return transactionHistory_;
    }

private:
    std::string accountNumber_;
    double balance_;
    std::vector<std::string> transactionHistory_;
};

int main() {
    BankAccount account1("12345", 1000.0);
    BankAccount account2("67890", 500.0);

    account1.deposit(500.0);
    account1.withdraw(200.0);
    account1.transfer(account2, 300.0);

    std::cout << "Account 1 Balance: " << account1.getBalance() << std::endl;
    std::cout << "Account 1 Transaction History:" << std::endl;
    for (const auto& transaction : account1.getTransactionHistory()) {
        std::cout << transaction << std::endl;
    }

    std::cout << "Account 2 Balance: " << account2.getBalance() << std::endl;
    std::cout << "Account 2 Transaction History:" << std::endl;
    for (const auto& transaction : account2.getTransactionHistory()) {
        std::cout << transaction << std::endl;
    }

    return 0;
}
