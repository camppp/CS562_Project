python
from typing import List

def generatePermutations(nums: List[int]) -> List[List[int]]:
    def backtrack(start, end, nums, result):
        if start == end:
            result.append(nums[:])
        else:
            for i in range(start, end):
                nums[start], nums[i] = nums[i], nums[start]
                backtrack(start + 1, end, nums, result)
                nums[start], nums[i] = nums[i], nums[start]

    result = []
    backtrack(0, len(nums), nums, result)
    return result
