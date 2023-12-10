class Transaction:
    def __init__(self, date, description, amount):
        self.date = date
        self.description = description
        self.amount = amount

class Account:
    def __init__(self, name):
        self.name = name
        self.transactions = []

    def add_transaction(self, transaction):
        self.transactions.append(transaction)

    def calculate_balance(self):
        balance = 0
        for transaction in self.transactions:
            balance += transaction.amount
        return balance

    def display_transactions(self, account_name):
        if account_name == self.name:
            for transaction in self.transactions:
                print(f"{transaction.date}: {transaction.description} - {transaction.amount}")
        else:
            print("Account not found")

# Example usage
account1 = Account("Savings")
account1.add_transaction(Transaction("2022-01-01", "Initial deposit", 1000))
account1.add_transaction(Transaction("2022-01-05", "Utility bill", -100))
account1.add_transaction(Transaction("2022-01-10", "ATM withdrawal", -200))

print(f"Balance for {account1.name}: {account1.calculate_balance()}")

account1.display_transactions("Savings")
