#include <iostream>
#include <string>
using namespace std;

class BigInt {
public:
    string b;

    int compare(BigInt x) {
        for (int i = 0; i < max(b.length(), x.b.length()); i++) {
            int p = '0', q = '0';
            if (i < b.length())     p = b[i];
            if (i < x.b.length())   q = x.b[i];
            if (p != q)
                return p < q ? 1 : -1;
        }
        return 0;
    }
};

int main() {
    // Test the compare method
    BigInt num1, num2;
    num1.b = "12345";
    num2.b = "12346";
    cout << num1.compare(num2) << endl;  // Output: -1

    num1.b = "54321";
    num2.b = "12345";
    cout << num1.compare(num2) << endl;  // Output: 1

    num1.b = "98765";
    num2.b = "98765";
    cout << num1.compare(num2) << endl;  // Output: 0

    return 0;
}
