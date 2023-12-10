bool canPartition(vector<int>& a) {
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    if (sum % 2 == 1) {
        return false;
    }
    int target = sum / 2;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        if (a[i] <= target) {
            left[i] = a[i];
        } else {
            right[i] = a[i];
        }
    }
    return canPartitionHelper(left, right, target);
}

bool canPartitionHelper(vector<int>& left, vector<int>& right, int target) {
    int n = left.size();
    if (n == 0) {
        return true;
    }
    if (left[0] > target || right[0] > target) {
        return false;
    }
    return canPartitionHelper(left.subvector(1, n), right.subvector(1, n), target - left[0]);
}
