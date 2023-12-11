#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next!= nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void remove(int val) {
        if(head == nullptr) {
            return;
        }
        if(head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            while(temp->next!= nullptr && temp->next->data!= val) {
                temp = temp->next;
            }
            if(temp->next!= nullptr) {
                Node* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
            }
        }
    }

    void print() {
        Node* temp = head;
        while(temp!= nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); // Output: 1 2 3
    list.remove(2);
    list.print(); // Output: 1 3
    return 0;
}