#include <stdio.h>
#include <string.h>

typedef struct {
  int accountNumber;
  float balance;
  char ownerName[50];
} Account;

Account createAccount(int accountNumber, float initialBalance, const char* ownerName) {
  Account newAccount;
  newAccount.accountNumber = accountNumber;
  newAccount.balance = initialBalance;
  strcpy(newAccount.ownerName, ownerName);
  return newAccount;
}

void deposit(Account *account, float amount) {
  account->balance += amount;
  printf("Deposited %.2f into account %d\n", amount, account->accountNumber);
}

void withdraw(Account *account, float amount) {
  if (account->balance >= amount) {
    account->balance -= amount;
    printf("Withdrawn %.2f from account %d\n", amount, account->accountNumber);
  } else {
    printf("Insufficient funds in account %d\n", account->accountNumber);
  }
}

void checkBalance(Account account) {
  printf("Account Number: %d\n", account.accountNumber);
  printf("Owner's Name: %s\n", account.ownerName);
  printf("Current Balance: %.2f\n", account.balance);
}

int main() {
  printf("Welcome to the Simple Banking System!\n");

  Account account1 = createAccount(1001, 500.0, "Alice");
  Account account2 = createAccount(1002, 1000.0, "Bob");

  deposit(&account1, 200.0);
  withdraw(&account2, 300.0);
  checkBalance(account1);
  checkBalance(account2);

  return 0;
}
