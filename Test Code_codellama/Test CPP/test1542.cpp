class BankAccount {
public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
        minBalance = 100;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance - amount < minBalance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() {
        return balance;
    }

private:
    double balance;
    double minBalance;
};
