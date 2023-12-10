class BankAccount {
public:
    // Default constructor
    BankAccount() : balance(0) {}

    // Parameterized constructor
    BankAccount(int initialBalance) : balance(initialBalance) {}

    // Copy constructor
    BankAccount(const BankAccount& other) : balance(other.balance) {}

    // Assignment operator overload
    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            balance = other.balance;
        }
        return *this;
    }

    // Destructor
    ~BankAccount() {
        cout << "Account closed" << endl;
    }

    // Deposit funds
    void deposit(int amount) {
        balance += amount;
    }

    // Withdraw funds
    void withdraw(int amount) {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;
        }
    }

    // Get current balance
    int getBalance() {
        return balance;
    }

private:
    int balance;
};
