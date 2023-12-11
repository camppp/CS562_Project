#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a;
    cin >> a;

    double sum = 0;
    for (int i = 0; i < a; i++) {
        int num;
        cin >> num;
        sum += num;
    }

    double average = sum / a;
    cout << fixed << setprecision(3) << average << endl;

    return 0;
}
