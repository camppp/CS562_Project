#include <iostream>
#include <set>
using namespace std;

int calculateProduct(int n, int b, set<int> v, set<int> u) {
    u.insert(b);
    return (n-v.size())*(n-u.size());
}
