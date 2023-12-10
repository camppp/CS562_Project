#include <iostream>
#include <unordered_map>

namespace elle {
  namespace reactor {
    class Bank {
    private:
      struct Account {
        double balance;
      };

      std::unordered_map<int, Account> accounts;
      int nextAccountNumber;

    public:
      Bank() : nextAccountNumber(1) {}

      int createAccount() {
        accounts[nextAccountNumber] = Account{0.0};
        return nextAccountNumber++;
      }

      void deposit(int accountNumber, double amount) {
        accounts[accountNumber].balance += amount;
      }

      void withdraw(int accountNumber, double amount) {
        if (accounts[accountNumber].balance >= amount) {
          accounts[accountNumber].balance -= amount;
        } else {
          std::cout << "Insufficient funds" << std::endl;
        }
      }

      double getBalance(int accountNumber) {
        return accounts[accountNumber].balance;
      }

      void transfer(int fromAccount, int toAccount, double amount) {
        if (accounts[fromAccount].balance >= amount) {
          accounts[fromAccount].balance -= amount;
          accounts[toAccount].balance += amount;
        } else {
          std::cout << "Insufficient funds for transfer" << std::endl;
        }
      }
    };
  }
}

int main() {
  elle::reactor::Bank bank;

  int account1 = bank.createAccount();
  int account2 = bank.createAccount();

  bank.deposit(account1, 1000.0);
  bank.withdraw(account1, 200.0);
  bank.transfer(account1, account2, 300.0);

  std::cout << "Account 1 balance: " << bank.getBalance(account1) << std::endl;
  std::cout << "Account 2 balance: " << bank.getBalance(account2) << std::endl;

  return 0;
}
