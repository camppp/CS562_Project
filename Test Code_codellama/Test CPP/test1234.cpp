#include <stdio.h>

// Define the Account structure
struct Account {
  int accountNumber;
  float balance;
  char ownerName[50];
};

// Define the createAccount function
struct Account createAccount(int accountNumber, float initialBalance, char ownerName[50]) {
  struct Account account;
  account.accountNumber = accountNumber;
  account.balance = initialBalance;
  strcpy(account.ownerName, ownerName);
  return account;
}

// Define the deposit function
void deposit(struct Account account, float amount) {
  account.balance += amount;
}

// Define the withdraw function
void withdraw(struct Account account, float amount) {
  if (account.balance >= amount) {
    account.balance -= amount;
  } else {
    printf("Insufficient funds.\n");
  }
}

// Define the checkBalance function
void checkBalance(struct Account account) {
  printf("Account number: %d\n", account.accountNumber);
  printf("Owner name: %s\n", account.ownerName);
  printf("Current balance: %f\n", account.balance);
}

int main() {
  // Create an account
  struct Account account1 = createAccount(1234, 1000.0, "John Doe");

  // Deposit money
  deposit(account1, 500.0);

  // Withdraw money
  withdraw(account1, 200.0);

  // Check balance
  checkBalance(account1);

  return 0;
}
