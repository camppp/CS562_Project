#include <iostream>

class WindowSystem {
private:
    int mMinScreenHeight;
    int mMaxScreenHeight;

public:
    WindowSystem(int minScreenHeight, int maxScreenHeight) : mMinScreenHeight(minScreenHeight), mMaxScreenHeight(maxScreenHeight) {}

    int checkHeightBounds(int height) const {
        if (height < mMinScreenHeight) {
            return mMinScreenHeight;
        }
        if (height > mMaxScreenHeight) {
            return mMaxScreenHeight;
        }
        return height;
    }
};

int main() {
    // Example usage
    WindowSystem window(200, 800);
    std::cout << window.checkHeightBounds(150) << std::endl;  // Output: 200
    std::cout << window.checkHeightBounds(850) << std::endl;  // Output: 800
    std::cout << window.checkHeightBounds(500) << std::endl;  // Output: 500
    return 0;
}
