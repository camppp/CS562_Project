#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void push_back(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
        size++;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = nullptr;
        delete current;
        size--;
    }

    int get_size() {
        return size;
    }

    std::string to_string() {
        std::string result;
        Node* current = head;
        while (current != nullptr) {
            result += std::to_string(current->data) + " ";
            current = current->next;
        }
        return result;
    }

    bool find_exec_name_list() {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == "label") {
                current = current->next;
                if (current->data == "length") {
                    return true;
                }
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinkedList exec_name_list;
    exec_name_list.push_back("label");
    exec_name_list.push_back("length");

    if (exec_name_list.find_exec_name_list()) {
        std::cout << "Both 'label' and 'length' found in the list" << std::endl;
    } else {
        std::cout << "Either 'label' or 'length' is missing from the list" << std::endl;
    }

    return 0;
}
