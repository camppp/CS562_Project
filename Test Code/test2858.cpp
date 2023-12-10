#include <iostream>

class GameUnit {
private:
    bool mIsCurrentUnit;

public:
    GameUnit() : mIsCurrentUnit(false) {}

    void SetActiveUnit(bool isActive) {
        mIsCurrentUnit = isActive;
    }

    bool IsCurrentUnit() const {
        return mIsCurrentUnit;
    }
};

int main() {
    GameUnit unit;
    std::cout << "Is current unit: " << unit.IsCurrentUnit() << std::endl;  // Output: Is current unit: 0

    unit.SetActiveUnit(true);
    std::cout << "Is current unit: " << unit.IsCurrentUnit() << std::endl;  // Output: Is current unit: 1

    return 0;
}
