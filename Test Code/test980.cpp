// The solution provided is a complete implementation of the Bank class in C++ based on the given specifications.

#include <iostream>
#include <vector>
#include <string>

class Account {
public:
    Account(int account_number, const std::string& customer_name) : account_number_(account_number), customer_name_(customer_name), balance_(0) {}

    int get_account_number() const {
        return account_number_;
    }

    std::string get_customer_name() const {
        return customer_name_;
    }

    int get_balance() const {
        return balance_;
    }

    void deposit(int amount) {
        balance_ += amount;
    }

    bool withdraw(int amount) {
        if (balance_ >= amount) {
            balance_ -= amount;
            return true;
        }
        return false;
    }

private:
    int account_number_;
    std::string customer_name_;
    int balance_;
};

class Bank {
public:
    Bank() {}

    void create_account(const std::string& customer_name) {
        accounts_.emplace_back(next_account_number_++, customer_name);
    }

    void deposit(int account_number, int amount) {
        for (auto& account : accounts_) {
            if (account.get_account_number() == account_number) {
                account.deposit(amount);
                return;
            }
        }
        std::cout << "Account not found" << std::endl;
    }

    void withdraw(int account_number, int amount) {
        for (auto& account : accounts_) {
            if (account.get_account_number() == account_number) {
                if (!account.withdraw(amount)) {
                    std::cout << "Insufficient funds" << std::endl;
                }
                return;
            }
        }
        std::cout << "Account not found" << std::endl;
    }

    void transfer(int source_account_number, int destination_account_number, int amount) {
        Account* source_account = nullptr;
        Account* destination_account = nullptr;
        for (auto& account : accounts_) {
            if (account.get_account_number() == source_account_number) {
                source_account = &account;
            }
            if (account.get_account_number() == destination_account_number) {
                destination_account = &account;
            }
        }
        if (source_account && destination_account) {
            if (source_account->withdraw(amount)) {
                destination_account->deposit(amount);
            } else {
                std::cout << "Insufficient funds" << std::endl;
            }
        } else {
            std::cout << "One or both accounts not found" << std::endl;
        }
    }

    int get_balance(int account_number) const {
        for (const auto& account : accounts_) {
            if (account.get_account_number() == account_number) {
                return account.get_balance();
            }
        }
        return -1;  // Account not found
    }

private:
    std::vector<Account> accounts_;
    int next_account_number_ = 1;
};

int main() {
    Bank bank;
    bank.create_account("Alice");
    bank.create_account("Bob");

    bank.deposit(1, 1000);
    bank.withdraw(1, 100);
    bank.transfer(1, 2, 200);

    std::cout << "Alice's balance: " << bank.get_balance(1) << std::endl;
    std::cout << "Bob's balance: " << bank.get_balance(2) << std::endl;

    return 0;
}
