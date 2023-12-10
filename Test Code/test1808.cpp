#include <iostream>
#include <vector>
using namespace std;

class CustomArray {
private:
    vector<int> arr;
public:
    CustomArray(int n) : arr(n, 0) {}

    void change(int pos, int val) {
        arr[pos] = val;
    }

    int get(int l, int r) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {
    int n, t, pos, val, l, r;
    cin >> n;
    CustomArray T(n);
    while (n --> 0) {
        cin >> t;
        if (t == 1) {
            cin >> pos >> val;
            T.change(pos, val);
        } else {
            cin >> l >> r;
            cout << T.get(l, r) << '\n';
        }
    }
    return 0;
}
