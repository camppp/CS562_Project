import java.util.ArrayList;
import java.util.List;

public class Bank {
    private List<Account> accounts;

    public Bank() {
        accounts = new ArrayList<>();
    }

    public void addAccount(Account account) {
        accounts.add(account);
    }

    public List<Account> getAllAccounts() {
        return accounts;
    }

    public boolean transferFunds(Account fromAccount, Account toAccount, double amount) {
        if (fromAccount == null || toAccount == null || amount <= 0) {
            return false;
        }

        if (fromAccount.getBalance() < amount) {
            return false;
        }

        fromAccount.setBalance(fromAccount.getBalance() - amount);
        toAccount.setBalance(toAccount.getBalance)
    }
}