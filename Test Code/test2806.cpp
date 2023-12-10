#include <iostream>
#include <list>
#include <cassert>

std::list<int> removeValue(const std::list<int>& inputList, int valueToRemove) {
    std::list<int> modifiedList = inputList;
    modifiedList.remove(valueToRemove);
    return modifiedList;
}

int main() {
    std::list<int> mylist = {10, 20, 30, 30, 40, 50, 60, 80, 90, 30};
    mylist = removeValue(mylist, 30);

    // Verify the modified list
    std::list<int>::iterator it = mylist.begin();
    assert(*it == 10);
    ++it;
    assert(*it == 20);
    ++it;
    assert(*it == 40);
    ++it;
    assert(*it == 50);
    ++it;
    assert(*it == 60);
    ++it;
    assert(*it == 80);
    ++it;
    assert(*it == 90);
    assert(mylist.size() == 7);

    std::cout << "All assertions passed. Modified list after removal: ";
    for (int val : mylist) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
