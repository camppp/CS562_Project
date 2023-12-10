#include <iostream>
#include <map>

namespace elle::reactor {

class Bank {
public:
    Bank() : nextAccountNumber_(1) {}

    int createAccount() {
        int accountNumber = nextAccountNumber_++;
        accounts_[accountNumber] = 0;
        return accountNumber;
    }

    void deposit(int accountNumber, double amount) {
        accounts_[accountNumber] += amount;
    }

    void withdraw(int accountNumber, double amount) {
        accounts_[accountNumber] -= amount;
    }

    double getBalance(int accountNumber) {
        return accounts_[accountNumber];
    }

    void transfer(int fromAccount, int toAccount, double amount) {
        accounts_[fromAccount] -= amount;
        accounts_[toAccount] += amount;
    }

private:
    std::map<int, double> accounts_;
    int nextAccountNumber_;
};

} // namespace elle::reactor
