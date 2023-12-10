int calculateFinalBalance(const vector<int>& events) {
    int balance = 0;
    for (int event : events) {
        balance += event;
    }
    return balance;
}
