#include <eosio/eosio.hpp>

using namespace eosio;

class token : public contract {
public:
    token(name receiver, name code, datastream<const char *> ds)
        : contract(receiver, code, ds) {}

    // Action to transfer tokens from one account to another
    [[eosio::action]] void transfer(name from, name to, asset quantity, string memo) {
        require_auth(from);
        eosio_assert(quantity.symbol == symbol("WLIST", 4), "Invalid token symbol");
        eosio_assert(quantity.is_valid(), "Invalid token quantity");
        eosio_assert(quantity.amount > 0, "Token quantity must be positive");

        // Update the balance of the "from" account
        sub_balance(from, quantity);

        // Update the balance of the "to" account
        add_balance(to, quantity);

        // Log the transfer event
        print("Transfer from ", from, " to ", to, " quantity ", quantity, " memo ", memo);
    }

    // Action to query the balance of a specific account
    [[eosio::action]] void balance(name account) {
        require_auth(account);
        eosio_assert(account.is_valid(), "Invalid account name");

        // Query the balance of the "account" account
        asset balance = get_balance(account);

        // Log the balance
        print("Balance of ", account, " is ", balance);
    }

private:
    // Data structure to store the token balances of all accounts
    struct account_balance {
        name account;
        asset balance;

        uint64_t primary_key() const { return account.value; }
    };

    // Add a token to the balance of an account
    void add_balance(name account, asset quantity) {
        // Get the existing balance of the account
        auto existing_balance = get_balance(account);

        // Add the new token to the existing balance
        existing_balance += quantity;

        // Update the balance of the account
        set_balance(account, existing_balance);
    }

    // Subtract a token from the balance of an account
    void sub_balance(name account, asset quantity) {
        // Get the existing balance of the account
        auto existing_balance = get_balance(account);

        // Subtract the new token from the existing balance
        existing_balance -= quantity;

        // Update the balance of the account
        set_balance(account, existing_balance);
    }

    // Get the balance of an account
    asset get_balance(name account) {
        // Query the balance of the account from the table
        auto balance = get_table_entry<account_balance>(account);

        // Return the balance
        return balance.balance;
    }

    // Set the balance of an account
    void set_balance(name account, asset balance) {
        // Create a new entry in the table for the account
        auto entry = account_balance{account, balance};

        // Insert the entry into the table
        insert_table_entry(entry);
    }
};
