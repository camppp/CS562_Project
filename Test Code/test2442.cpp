int[] findMissingAndRepeating(int[] nums) {
    int n = nums.length;
    int[] counts = new int[n];

    for (int i = 0; i < n; i++) {
        counts[nums[i] - 1]++;
    }

    int missing1 = -1, missing2 = -1;
    for (int i = 0; i < n; i++) {
        if (counts[i] == 1) {
            if (missing1 == -1) {
                missing1 = i + 1;
            } else {
                missing2 = i + 1;
            }
        }
    }

    return new int[] { missing1, missing2 };
}
