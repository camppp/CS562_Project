namespace eosio {
  class [[eosio::contract("wlist.token")]] token : public contract {
  public:
    using contract::contract;

    // Data structure to store token balances
    struct [[eosio::table]] account {
      name owner;
      uint64_t balance;

      uint64_t primary_key() const { return owner.value; }
    };
    typedef multi_index<"accounts"_n, account> accounts;

    // Constructor
    token(name receiver, name code, datastream<const char *> ds)
        : contract(receiver, code, ds) {}

    // Action to transfer tokens from one account to another
    [[eosio::action]]
    void transfer(name from, name to, uint64_t quantity) {
      require_auth(from);

      accounts from_acnts(get_self(), from.value);
      auto from_itr = from_acnts.find(from.value);
      eosio_assert(from_itr != from_acnts.end(), "Sender account does not exist");
      eosio_assert(from_itr->balance >= quantity, "Insufficient balance");

      accounts to_acnts(get_self(), to.value);
      auto to_itr = to_acnts.find(to.value);
      if (to_itr == to_acnts.end()) {
        to_acnts.emplace(from, [&](auto &a) {
          a.owner = to;
          a.balance = quantity;
        });
      } else {
        to_acnts.modify(to_itr, same_payer, [&](auto &a) {
          a.balance += quantity;
        });
      }

      from_acnts.modify(from_itr, same_payer, [&](auto &a) {
        a.balance -= quantity;
      });
    }

    // Action to query the balance of a specific account
    [[eosio::action]]
    uint64_t get_balance(name owner) {
      accounts acnts(get_self(), owner.value);
      auto itr = acnts.find(owner.value);
      eosio_assert(itr != acnts.end(), "Account does not exist");
      return itr->balance;
    }
  };
}  // namespace eosio
