class WindowSystem {
public:
    WindowSystem(int minScreenHeight, int maxScreenHeight) : mMinScreenHeight(minScreenHeight), mMaxScreenHeight(maxScreenHeight) {}

    int checkHeightBounds(int height) {
        if (height < mMinScreenHeight) {
            return mMinScreenHeight;
        } else if (height > mMaxScreenHeight) {
            return mMaxScreenHeight;
        } else {
            return height;
        }
    }

private:
    int mMinScreenHeight;
    int mMaxScreenHeight;
};
