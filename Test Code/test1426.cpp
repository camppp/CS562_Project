void sortStack(std::stack<int>& s) {
    std::stack<int> tempStack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}
