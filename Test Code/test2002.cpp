#include <iostream>

class Item {
public:
    int mnId;
};

class ItemList {
private:
    Item* mHead;
    Item* mCurrent;

public:
    ItemList() : mHead(nullptr), mCurrent(nullptr) {
        // Initialize the list
        // For example, add items to the list
    }

    void AddItem(int id) {
        // Add an item with the given id to the list
        Item* newItem = new Item();
        newItem->mnId = id;
        newItem->Next = mHead;
        mHead = newItem;
    }

    Item* Next() {
        if (mCurrent == nullptr) {
            mCurrent = mHead;
        } else {
            mCurrent = mCurrent->Next;
        }
        return mCurrent;
    }
};

class CustomIterator {
private:
    ItemList* mpItemList;
    Item* mCurrent;

public:
    CustomIterator(ItemList* pList) : mpItemList(pList), mCurrent(nullptr) {
        // Constructor that takes a pointer to an ItemList object
    }

    Item* Next() {
        // Method that returns the next item in the list or nullptr if there are no more items
        return mpItemList->Next();
    }

    bool HasNext() {
        // Method that returns true if there are more items in the list, and false otherwise
        return mpItemList->Next() != nullptr;
    }
};

int main() {
    ItemList* mpItemList = new ItemList();
    mpItemList->AddItem(1);
    mpItemList->AddItem(2);
    mpItemList->AddItem(3);

    CustomIterator iterator(mpItemList);

    while (iterator.HasNext()) {
        Item* pItem = iterator.Next();
        std::cout << "Processing item with id: " << pItem->mnId << std::endl;
    }

    return 0;
}
