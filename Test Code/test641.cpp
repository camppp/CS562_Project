++
#include <unordered_map>

int countUniqueElements(int arr[], int size) {
    std::unordered_map<int, int> frequencyMap;
    int uniqueCount = 0;

    // Count the frequency of each element in the array
    for (int i = 0; i < size; i++) {
        frequencyMap[arr[i]]++;
    }

    // Count the number of unique elements
    for (const auto& pair : frequencyMap) {
        if (pair.second == 1) {
            uniqueCount++;
        }
    }

    return uniqueCount;
}
