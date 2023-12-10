#include <cstddef>

template <typename T>
class custom_linked_list {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node _first;
    Node _last;
    size_t _length;

public:
    custom_linked_list() : _length(0) {
        this->_last.next = &_first;
    }

    virtual ~custom_linked_list() {
        this->clear();
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = _first.next;
        _first.next = newNode;
        if (_last.next == &_first) {
            _last.next = newNode;
        }
        _length++;
    }

    void pop_front() {
        if (_first.next != nullptr) {
            Node* temp = _first.next;
            _first.next = temp->next;
            delete temp;
            if (_first.next == nullptr) {
                _last.next = &_first;
            }
            _length--;
        }
    }

    void clear() {
        while (_first.next != nullptr) {
            Node* temp = _first.next;
            _first.next = temp->next;
            delete temp;
        }
        _last.next = &_first;
        _length = 0;
    }

    size_t size() const {
        return _length;
    }

    bool empty() const {
        return _length == 0;
    }
};
