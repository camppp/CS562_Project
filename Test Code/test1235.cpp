#include <iostream>
#include <string>

class Customer {
private:
    std::string name;
    char initial;
    int account;

public:
    void set_name(const std::string& n) {
        name = n;
    }

    void set_initial(char i) {
        initial = i;
    }

    void set_account(int a) {
        account = a;
    }

    std::string get_name() {
        return name;
    }

    char get_initial() {
        return initial;
    }

    int get_account() {
        return account;
    }
};

int main() {
    Customer customer;
    customer.set_name("John Doe");
    customer.set_initial('J');
    customer.set_account(12345);

    std::cout << "Customer Name: " << customer.get_name() << std::endl;
    std::cout << "Customer Initial: " << customer.get_initial() << std::endl;
    std::cout << "Customer Account Number: " << customer.get_account() << std::endl;

    return 0;
}
