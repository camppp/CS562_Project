std::vector<int> mergeSort(std::vector<int> data, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(data, left, middle);
        mergeSort(data, middle + 1, right);
        merge(data, left, middle, right);
    }
    return data;
}

std::vector<int> merge(std::vector<int> data, int right, int left, int middle) {
    std::vector<int> leftSubarray(data.begin() + left, data.begin() + middle + 1);
    std::vector<int> rightSubarray(data.begin() + middle + 1, data.begin() + right + 1);
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < leftSubarray.size() && j < rightSubarray.size()) {
        if (leftSubarray[i] <= rightSubarray[j]) {
            result.push_back(leftSubarray[i++]);
        } else {
            result.push_back(rightSubarray[j++]);
        }
    }
    while (i < leftSubarray.size()) {
        result.push_back(leftSubarray[i++]);
    }
    while (j < rightSubarray.size()) {
        result.push_back(rightSubarray[j++]);
    }
    return result;
}
