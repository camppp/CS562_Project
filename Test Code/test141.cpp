#include <queue>
#include <functional>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // to store the smaller half of the numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // to store the larger half of the numbers

public:
    MedianFinder() {}

    void addNumber(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Rebalance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};
