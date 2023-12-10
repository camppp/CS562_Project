python
def countPairsWithSum(nums, target):
    count = 0
    seen = set()
    for num in nums:
        complement = target - num
        if complement in seen:
            count += 1
        seen.add(num)
    return count
