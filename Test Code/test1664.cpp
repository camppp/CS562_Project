#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countElementsLessThanX(int a[], int n, int queries[], int q) {
    vector<int> result;
    sort(a, a + n); // Sort the array to perform binary search

    for (int i = 0; i < q; i++) {
        int count = upper_bound(a, a + n, queries[i]) - a; // Count elements less than the query value
        result.push_back(count);
    }

    return result;
}
