#include <iostream>
#include <set>
using namespace std;

int calculateProduct(int n, int b, set<int> v, set<int> u) {
    u.insert(b);  // Insert the value b into set u
    int result = (n - v.size()) * (n - u.size());  // Calculate the product of the differences between n and the sizes of sets v and u
    return result;  // Return the calculated product
}
