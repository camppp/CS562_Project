std::vector<Transaction> BankAccount::getTransactions() const {
    std::vector<Transaction> transactions;
    for (const auto& transaction : this->transactions) {
        Transaction t;
        t.isDebit = transaction.isDebit;
        t.amount = transaction.amount;
        t.date = transaction.date;
        transactions.push_back(t);
    }
    return transactions;
}
