// Linked list node structure
struct Node {
    int data;
    Node* next;
};

// Linked list structure
struct LinkedList {
    Node* head;
    Node* tail;
    int size;
};

// Linked list functions
void LinkedList::insert(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

void LinkedList::delete(int data) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            size--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void LinkedList::traverse() {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
