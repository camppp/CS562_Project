class BankAccount {
private:
    int balance;
    int total_transactions;

public:
    BankAccount() : balance(0), total_transactions(0) {}

    void deposit(int amount) {
        balance += amount;
        total_transactions++;
    }

    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            total_transactions++;
        }
    }

    int get_balance() {
        return balance;
    }

    int get_total_transactions() {
        return total_transactions;
    }
};
