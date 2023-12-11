def kSmallestPairs(nums1, nums2, k):
    result = []
    i = 0
    j = 0
    while i < len(nums1) and j < len(nums2) and k > 0:
        if nums1[i] + nums2[j] <= k:
            result.append([nums1[i], nums2[j]])
            k -= nums1[i] + nums2[j]
            i += 1
            j += 1
        elif nums1[i] + nums2[j] > k:
            j += 1
    return result