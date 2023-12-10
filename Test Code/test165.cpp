double findMedian(std::vector<int>& nums) {
    // Sort the vector in ascending order
    std::sort(nums.begin(), nums.end());

    // If the vector has an odd number of elements, return the middle element
    if (nums.size() % 2 == 1) {
        return nums[nums.size() / 2];
    }

    // If the vector has an even number of elements, return the average of the two middle elements
    int mid1 = nums.size() / 2 - 1;
    int mid2 = nums.size() / 2;
    return (nums[mid1] + nums[mid2]) / 2.0;
}
