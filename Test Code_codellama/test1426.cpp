void sortStack(std::stack<int>& s) {
    std::stack<int> temp;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        while (!temp.empty() && temp.top() > top) {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(top);
    }
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}
