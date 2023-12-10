#include <iostream>
#include <string>
#include <vector>

class Account {
public:
    Account(int initialBalance) {
        accountNumber = generateAccountNumber();
        balance = initialBalance;
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    int getBalance() {
        return balance;
    }

    static int getTotalBalance() {
        int totalBalance = 0;
        for (auto& account : accounts) {
            totalBalance += account.getBalance();
        }
        return totalBalance;
    }

private:
    int accountNumber;
    int balance;

    static int generateAccountNumber() {
        static int accountNumber = 1000;
        return accountNumber++;
    }

    static std::vector<Account> accounts;
};

std::vector<Account> Account::accounts;

int main() {
    Account account1(1000);
    Account account2(2000);

    account1.deposit(500);
    account2.withdraw(100);

    std::cout << "Account 1 balance: " << account1.getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2.getBalance() << std::endl;
    std::cout << "Total balance: " << Account::getTotalBalance() << std::endl;

    return 0;
}
