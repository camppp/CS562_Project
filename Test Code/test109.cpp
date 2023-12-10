class MinStack {
private:
    struct Node {
        int val;
        int min;
        Node* next;
        Node(int x, int m, Node* n) : val(x), min(m), next(n) {}
    };

    Node* topNode;

public:
    MinStack() {
        topNode = nullptr;
    }

    void push(int x) {
        if (topNode == nullptr) {
            topNode = new Node(x, x, nullptr);
        } else {
            topNode = new Node(x, std::min(x, topNode->min), topNode);
        }
    }

    void pop() {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        return topNode->val;
    }

    int getMin() {
        return topNode->min;
    }
};
