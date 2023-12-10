python
class BankAccount:
    def __init__(self):
        self._balance = 0
        self._total_transactions = 0

    def deposit(self, amount):
        self._balance += amount
        self._total_transactions += 1

    def withdraw(self, amount):
        if self._balance >= amount:
            self._balance -= amount
            self._total_transactions += 1
        else:
            print("Insufficient funds")

    def get_balance(self):
        return self._balance

    def get_total_transactions(self):
        return self._total_transactions
