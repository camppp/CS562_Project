python
from typing import List

def count_unique_numbers(nums: List[int]) -> int:
    num_count = {}
    for num in nums:
        if num in num_count:
            num_count[num] += 1
        else:
            num_count[num] = 1
    unique_count = 0
    for count in num_count.values():
        if count == 1:
            unique_count += 1
    return unique_count
