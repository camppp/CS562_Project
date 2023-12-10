class MedianFinder {
private:
    // The set of integers
    set<int> nums;

    // The median of the set
    double median;

public:
    // Constructor
    MedianFinder() {
        // Initialize the set and the median
        nums = set<int>();
        median = 0.0;
    }

    // Add a new integer to the set
    void addNumber(int num) {
        // Add the number to the set
        nums.insert(num);

        // Update the median
        updateMedian();
    }

    // Return the median of the set
    double findMedian() {
        return median;
    }

private:
    // Update the median based on the current set of numbers
    void updateMedian() {
        // If the set is empty, return 0
        if (nums.empty()) {
            median = 0.0;
            return;
        }

        // If the set has only one element, return that element
        if (nums.size() == 1) {
            median = *nums.begin();
            return;
        }

        // If the set has an odd number of elements, return the middle element
        if (nums.size() % 2 == 1) {
            median = *nums.begin();
            return;
        }

        // If the set has an even number of elements, return the average of the two middle elements
        auto it = nums.begin();
        advance(it, nums.size() / 2 - 1);
        median = (*it + *(it + 1)) / 2;
    }
};
