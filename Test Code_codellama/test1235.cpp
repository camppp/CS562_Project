#include <iostream>

class Customer {
private:
    std::string name;
    char initial;
    int account;

public:
    Customer(const std::string& name, char initial, int account)
        : name(name), initial(initial), account(account) {}

    std::string get_name() const { return name; }
    char get_initial() const { return initial; }
    int get_account() const { return account; }
};

int main() {
    Customer customer("John Doe", 'J', 123456789);

    std::cout << "Name: " << customer.get_name() << std::endl;
    std::cout << "Initial: " << customer.get_initial() << std::endl;
    std::cout << "Account: " << customer.get_account() << std::endl;

    return 0;
}
