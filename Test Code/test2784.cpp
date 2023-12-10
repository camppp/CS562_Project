class RedoDelete {
public:
    RedoDelete() {}
    ~RedoDelete() {
        while (!stack.empty()) {
            delete stack.top();
            stack.pop();
        }
    }

    void redo(int val) {
        stack.push(new int(val));
    }

    void delete() {
        if (!stack.empty()) {
            delete stack.top();
            stack.pop();
        }
    }

private:
    std::stack<int*> stack;
};
