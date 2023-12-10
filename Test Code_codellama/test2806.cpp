#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> removeValue(const std::vector<int>& inputVector, int valueToRemove) {
    std::vector<int> modifiedVector = inputVector;
    modifiedVector.erase(std::remove(modifiedVector.begin(), modifiedVector.end(), valueToRemove), modifiedVector.end());
    return modifiedVector;
}

int main() {
    std::vector<int> myvector = {10, 20, 30, 30, 40, 50, 60, 80, 90, 30};
    myvector = removeValue(myvector, 30);

    // Verify the modified vector
    std::vector<int>::iterator it = myvector.begin();
    assert(*it == 10);
    ++it;
    assert(*it == 20);
    ++it;
    assert(*it == 40);
    ++it;
    assert(*it == 50);
    ++it;
    assert(*it == 60);
    ++it;
    assert(*it == 80);
    ++it;
    assert(*it == 90);
    assert(myvector.size() == 7);

    std::cout << "All assertions passed. Modified vector after removal: ";
    for (int val : myvector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
