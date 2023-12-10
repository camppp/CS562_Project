class Unit {
public:
    Unit(bool isCurrentUnit = false) : mIsCurrentUnit(isCurrentUnit) {}

    void SetActiveUnit(bool isCurrentUnit) {
        mIsCurrentUnit = isCurrentUnit;
    }

    bool IsCurrentUnit() {
        return mIsCurrentUnit;
    }

private:
    bool mIsCurrentUnit;
};
