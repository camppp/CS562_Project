def count_unique_numbers(nums: List[int]) -> int:
    unique_nums = set()
    for num in nums:
        if num not in unique_nums:
            unique_nums.add(num)
    return len(unique_nums)
