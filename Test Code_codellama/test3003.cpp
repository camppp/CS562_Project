int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Initialize the minimum number of jumps to reach the last index
    int minJumps = 1;

    // Initialize the maximum reachable index
    int maxReach = nums[0];

    // Iterate through the array
    for (int i = 1; i < n; i++) {
        // If the current index is beyond the maximum reachable index,
        // then we need to update the maximum reachable index and the
        // minimum number of jumps to reach the last index
        if (i > maxReach) {
            minJumps++;
            maxReach = nums[i];
        }
    }

    return minJumps;
}
