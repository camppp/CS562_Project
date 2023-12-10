python
def longestIncreasingSubsequence(nums):
    n = len(nums)
    if n == 0:
        return 0

    dp = [1] * n  # Initialize the dp array with 1 as the minimum LIS length for each element

    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)  # Update the LIS length for element i

    return max(dp)  # Return the maximum LIS length found in the dp array
