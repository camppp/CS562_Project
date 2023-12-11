class BankAccount:
   def __init__(self, account_number, initial_balance):
       self.account_number = account_number
       self.balance = initial_balance
       self.total_accounts = 0

   def deposit(self, amount):
       self.balance += amount

   def withdraw(self, amount):
       self.balance -= amount

   def get_balance(self):
       return self.balance

   def total_accounts(self):
       return self.total_accounts