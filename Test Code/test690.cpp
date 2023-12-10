#include <vector>

int calculateFinalBalance(const std::vector<int>& events) {
    int balance = 0;
    for (int event : events) {
        balance += event;
        if (event == 0) {
            break;
        }
    }
    return balance;
}
