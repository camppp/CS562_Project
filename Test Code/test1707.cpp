#include <vector>
#include <algorithm>

class StableSortableArray {
private:
  std::vector<int> elements;

public:
  StableSortableArray(std::vector<int> elements) : elements(elements) {}

  void stableSort() {
    std::stable_sort(elements.begin(), elements.end());
  }

  bool isStable() {
    for (size_t i = 1; i < elements.size(); ++i) {
      if (elements[i] == elements[i - 1]) {
        // If the current element is equal to the previous element,
        // and the current element's index is less than the previous element's index,
        // then the sorting is not stable
        if (elements[i] < elements[i - 1]) {
          return false;
        }
      }
    }
    return true;
  }
};
