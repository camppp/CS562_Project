#include <iostream>
#include <vector>

class Account {
private:
    static int nextAccountNumber;
    int accountNumber;
    int balance;

public:
    Account(int initialBalance) : accountNumber(nextAccountNumber++), balance(initialBalance) {}

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << " into account " << accountNumber << std::endl;
        } else {
            std::cout << "Invalid deposit amount" << std::endl;
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn " << amount << " from account " << accountNumber << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount" << std::endl;
        }
    }

    int getBalance() const {
        return balance;
    }

    static int getTotalBalance(const std::vector<Account>& accounts) {
        int totalBalance = 0;
        for (const auto& account : accounts) {
            totalBalance += account.getBalance();
        }
        return totalBalance;
    }
};

int Account::nextAccountNumber = 1;

int main() {
    std::vector<Account> accounts;

    Account account1(100);
    account1.deposit(50);
    account1.withdraw(30);
    accounts.push_back(account1);

    Account account2(200);
    account2.deposit(100);
    account2.withdraw(50);
    accounts.push_back(account2);

    std::cout << "Total balance of all accounts: " << Account::getTotalBalance(accounts) << std::endl;

    return 0;
}
