#include <iostream>
#include <vector>
using namespace std;

vector<int> convolution(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> c(2 * n - 1, 0);
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = max(0, i - n + 1); j <= min(i, n - 1); ++j) {
            c[i] += a[j] * b[i - j];
        }
    }
    return c;
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    vector<int> result = convolution(a, b);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
