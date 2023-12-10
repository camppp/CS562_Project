#include <iostream>
#include <vector>
using namespace std;

vector<int> findSubarray(vector<int> &arr, int targetSum) {
    int n = arr.size();
    int start = 0, curSum = arr[0];
    bool flag = true;
    
    for (int i = 1; i <= n; i++) {
        while (curSum > targetSum && start < i - 1) {
            curSum -= arr[start];
            start++;
        }
        
        if (curSum == targetSum) {
            cout << start + 1 << " " << i << endl;
            flag = false;
            break;
        }
        
        if (i < n)
            curSum += arr[i];
    }
    
    if (flag) {
        cout << "No subarray found";
    }
    
    return {start + 1, i};
}

int main() {
    vector<int> arr = {1, 4, 20, 3, 10, 5};
    int targetSum = 33;
    vector<int> result = findSubarray(arr, targetSum);
    return 0;
}
