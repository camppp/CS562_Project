#ifndef __LIST_NODE_INL__
#define __LIST_NODE_INL__

#pragma once

#include <iostream>

__BEGIN_NAMESPACE__
////////////////////////////////////////////////////////////////////////////////////////

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};

////////////////////////////////////////////////////////////////////////////////////////
__END_NAMESPACE__
#endif
