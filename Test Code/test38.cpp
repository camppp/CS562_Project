class MinStack {
private:
    stack<int> s;
    int min;

public:
    MinStack() {
        min = INT_MAX;
    }

    void push(int x) {
        s.push(x);
        if (x < min) {
            min = x;
        }
    }

    void pop() {
        s.pop();
        if (!s.empty()) {
            min = s.top();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min;
    }
};
