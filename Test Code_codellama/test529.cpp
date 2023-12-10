class NodeList {
public:
    // Constructor
    NodeList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor
    ~NodeList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Append a new Statement object to the end of the NodeList
    void append(const Statement& statement) {
        Node* newNode = new Node(statement);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Remove the Statement object at the specified index from the NodeList
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            head = head->next;
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node* current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }

    // Print the content of the NodeList
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->statement << std::endl;
            current = current->next;
        }
    }

private:
    // Node class
    class Node {
    public:
        Statement statement;
        Node* next;

        Node(const Statement& statement) : statement(statement), next(nullptr) {}
    };

    // Head and tail pointers
    Node* head;
    Node* tail;

    // Size of the NodeList
    int size;
};
