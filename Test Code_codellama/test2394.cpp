class BankAccount {
public:
    BankAccount(std::string accountNumber, double initialBalance) {
        accountNumber_ = accountNumber;
        balance_ = initialBalance;
        transactionHistory_.push_back("Initial Balance: " + std::to_string(initialBalance));
    }

    void deposit(double amount) {
        balance_ += amount;
        transactionHistory_.push_back("Deposit: " + std::to_string(amount));
    }

    void withdraw(double amount) {
        if (balance_ - amount < 0) {
            throw std::runtime_error("Insufficient funds");
        }
        balance_ -= amount;
        transactionHistory_.push_back("Withdrawal: " + std::to_string(amount));
    }

    void transfer(BankAccount& recipient, double amount) {
        if (balance_ - amount < 0) {
            throw std::runtime_error("Insufficient funds");
        }
        balance_ -= amount;
        recipient.deposit(amount);
        transactionHistory_.push_back("Transfer: " + std::to_string(amount) + " to " + recipient.getAccountNumber());
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
