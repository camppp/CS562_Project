python
def findUniqueElement(nums):
    unique_element = 0
    for num in nums:
        unique_element ^= num
    return unique_element
