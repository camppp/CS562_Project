// File: util.cpp
#include <sortnet/util.h>

namespace sortnet {
    void sortLinkedList(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return;  // No need to sort if the list is empty or has only one element
        }

        bool swapped;
        Node* temp;

        do {
            swapped = false;
            temp = head;

            while (temp->next != nullptr) {
                if (temp->data > temp->next->data) {
                    // Swap the data of the current and next nodes
                    int tempData = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tempData;
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }
}
