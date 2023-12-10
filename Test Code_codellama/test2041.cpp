#include <algorithm>
#include <cfloat>

void findMinMax(float arr[], int length, float& maxVal, float& minVal) {
    // Use std::minmax_element to find the minimum and maximum values in the array
    auto minmax = std::minmax_element(arr, arr + length);
    maxVal = *minmax.second;
    minVal = *minmax.first;
}
