#include <iostream>
#include <vector>
#include <algorithm>

class TripleMirrorFreqN {
private:
    std::vector<int> originalList;

public:
    TripleMirrorFreqN(const std::vector<int>& list) : originalList(list) {}

    int getFrequency(int value) {
        int frequency = std::count(originalList.begin(), originalList.end(), value);
        int mirroredFrequency = std::count(originalList.rbegin(), originalList.rend(), value);
        return frequency + mirroredFrequency * 3;  // Considering the list is mirrored three times
    }
};

int main() {
    std::vector<int> inputList = {1, 2, 3, 0, 4, 0, 3, 2, 1};  // Example input list
    TripleMirrorFreqN tripleMirrorFreqN(inputList);
    int valueToFind = 0;
    int frequency = tripleMirrorFreqN.getFrequency(valueToFind);
    std::cout << "Frequency of " << valueToFind << " in the mirrored list: " << frequency << std::endl;
    return 0;
}
