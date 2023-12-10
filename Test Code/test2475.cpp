#include <iostream>
#include <vector>

class QuickSort {
public:
    void quickSort(std::vector<int>& nums, int beg, int end) {
        if (beg < end) {
            int q = partition(nums, beg, end);
            quickSort(nums, beg, q - 1);
            quickSort(nums, q + 1, end);
        }
    }

private:
    int partition(std::vector<int>& nums, int beg, int end) {
        int pivot = nums[end];
        int i = beg - 1;
        for (int j = beg; j < end; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i + 1, end);
        return i + 1;
    }

    void swap(std::vector<int>& nums, int p, int q) {
        int tmp = nums[p];
        nums[p] = nums[q];
        nums[q] = tmp;
    }
};

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    QuickSort qs;
    qs.quickSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
