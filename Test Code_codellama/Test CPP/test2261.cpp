#include <iostream>
#include <vector>

using namespace std;

int sum_divisible(vector<int> arr, int divisor) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    vector<int> arr = {10, 5, 8, 12, 7};
    int divisor = 5;
    int sum = sum_divisible(arr, divisor);
    cout << "Sum of divisible elements: " << sum << endl;
    return 0;
}
