#include <iostream>

template <typename T, typename Node>
class forward_list_base {
public:
    typedef forward_list_base<T, Node> self_type;
    typedef Node node;

    class iterator : public rubbish::iterator<std::forward_iterator_tag, T> {
    private:
        Node* current;

    public:
        iterator(Node* node) : current(node) {}

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        T& operator*() {
            return current->data;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };

    Node* head;

    forward_list_base() : head(nullptr) {}

    void push_front(const T& value) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }
};

// Example usage
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

int main() {
    forward_list_base<int, Node> forward_list;
    forward_list.push_front(3);
    forward_list.push_front(2);
    forward_list.push_front(1);

    for (auto it = forward_list.begin(); it != forward_list.end(); ++it) {
        std::cout << *it << " ";
    }
    // Output: 1 2 3
    return 0;
}
