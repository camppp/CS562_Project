def find_max(nums):
    if len(nums) == 0:
        return None
    answer = nums[0]
    for num in nums:
        if num > answer:
            answer = num
    return answer