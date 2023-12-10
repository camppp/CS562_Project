#include <iostream>
#include <vector>

class Collection {
private:
    std::vector<int> items;

public:
    Collection(const std::vector<int>& inputItems) : items(inputItems) {}

    bool isEqual(const Collection& col) {
        if (items.size() != col.items.size()) {
            return false;
        }

        for (int i = 0, n = items.size(); i < n; ++i) {
            if (!(items[i] == col.items[i])) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Collection col1({1, 2, 3});
    Collection col2({1, 2, 3});
    Collection col3({1, 2, 4});

    std::cout << "col1 isEqual col2: " << std::boolalpha << col1.isEqual(col2) << std::endl;  // Output: true
    std::cout << "col1 isEqual col3: " << std::boolalpha << col1.isEqual(col3) << std::endl;  // Output: false

    return 0;
}
