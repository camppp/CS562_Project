#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <list>

template<typename Range1, typename Range2>
bool equal(Range1 const& _range1, Range2 const& _range2) {
    return std::equal(_range1.begin(), _range1.end(), _range2.begin(), _range2.end());
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::list<int> list1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 6};
    std::list<int> list2 = {1, 2, 3, 4, 5};

    bool result1 = equal(vec1, vec2);  // should return true
    bool result2 = equal(arr1, arr2);  // should return false
    bool result3 = equal(list1, list2);  // should return true

    std::cout << "result1: " << result1 << std::endl;
    std::cout << "result2: " << result2 << std::endl;
    std::cout << "result3: " << result3 << std::endl;

    return 0;
}
