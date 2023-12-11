import random

class BankAccount:
    def __init__(self, account_number, balance=0):
        self.account_number = account_number
        self.balance = balance

class BankingSystem:
    def __init__(self):
        self.accounts = {}

    def createAccount(self):
        account_number = random.randint(100000, 999999)
        while account_number in self.accounts:
            account_number = random.randint(100000, 999999)
        self.accounts[account_number] = BankAccount(account_number)
        return account_number

    def deposit(self, account_number, amount):
        if account_number in self.accounts:
            self.accounts[account_number].balance += amount
        else:
            print("Account not found")

    def withdraw(self, account_number, amount):
        if account_number in self.accounts:
            if self.accounts[account_number].balance >= amount:
                self.accounts[account_number].balance -= amount
            else:
                print("Insufficient balance")
        else:
            print("Account not found")

    def transfer(self, from_account_number, to_account_number, amount):
        if from_account_number in self.accounts and to_account_number in self.accounts:
            if self.accounts[from_account_number].balance >= amount:
                self.accounts[from_account_number].balance -= amount
                self.accounts[to_account_number].balance += amount
            else:
                print("Insufficient balance")
        else:
            print("One or both accounts not found")

    def totalBalance(self):
        return sum(account.balance for account in self.accounts.values())