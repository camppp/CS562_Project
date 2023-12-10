#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    std::map<int, int> myMap = { {4, 40}, {5, 50}, {6, 60} };
    for_each(myMap.cbegin(), myMap.cend(),
             [](const std::pair<int, int>& p) { std::cout << p.first << "->" << p.second << std::endl; });

    std::vector<int> vec;
    vec.push_back(1);

    // Complete the code by adding a lambda function to modify the vector
    std::for_each(myMap.begin(), myMap.end(), [&vec](const std::pair<int, int>& p) {
        if (p.first < vec.size()) {
            vec[p.first] *= p.second;
        }
    });

    // Print the modified vector
    for (int val : vec) {
        std::cout << val << " ";
    }

    return 0;
}
