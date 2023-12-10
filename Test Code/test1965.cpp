#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    int c;
    double b = 0;
    for (int i = 1; i <= a; i++) {
        cin >> c;
        b = b + c;
    }
    double d = a;
    double e = b;
    cout << (b / double(a));
    return 0;
}
