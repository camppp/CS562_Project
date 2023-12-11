#include <iostream>
#include <unordered_map>

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void transfer(Account& recipient, double amount) {
        if (balance >= amount) {
            balance -= amount;
            recipient.deposit(amount);
        } else {
            std::cout << "Insufficient funds for transfer" << std::endl;
        }
    }
};

class Bank {
private:
    std::unordered_map<int, Account> accounts;
    int nextAccountNumber;

public:
    Bank() : nextAccountNumber(1) {}

    void createAccount(double initialBalance) {
        accounts[nextAccountNumber] = Account(nextAccountNumber, initialBalance);
        nextAccountNumber++;
    }

    Account& getAccount(int accountNumber) {
        return accounts[accountNumber];
    }

    void transferFunds(int fromAccount, int toAccount, double amount) {
        Account& sender = accounts[fromAccount];
        Account& recipient = accounts[toAccount];
        sender.transfer(recipient, amount);
    }
};
