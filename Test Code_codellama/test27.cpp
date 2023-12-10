class BankAccount {
public:
    BankAccount(double initialBalance) : balance(initialBalance), totalTransactions(0) {}

    void deposit(double amount) {
        balance += amount;
        totalTransactions++;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            totalTransactions++;
        }
    }

    double getBalance() {
        return balance;
    }

    int getTotalTransactions() {
        return totalTransactions;
    }

private:
    double balance;
    int totalTransactions;
};
