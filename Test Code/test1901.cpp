#include <list>
#include <iostream>

int findSecondLargest(const std::list<int>& lst) {
    if (lst.size() < 2) {
        return -1; // Error value for lists with less than two elements
    }

    int firstMax = std::numeric_limits<int>::min();
    int secondMax = std::numeric_limits<int>::min();

    for (int num : lst) {
        if (num > firstMax) {
            secondMax = firstMax;
            firstMax = num;
        } else if (num > secondMax && num < firstMax) {
            secondMax = num;
        }
    }

    return secondMax;
}

int main() {
    std::list<int> lst = {3, 8, 1, 6, 4, 7, 2, 5};
    std::cout << "Second largest element: " << findSecondLargest(lst) << std::endl;
    return 0;
}
