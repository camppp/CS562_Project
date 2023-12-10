class KeyState {
public:
    KeyState(bool isPressed, bool isReleased, bool isDown, bool rawDownState)
        : mIsPressed(isPressed), mIsReleased(isReleased), mIsDown(isDown), mRawDownState(rawDownState) {}

    bool IsPressed() const { return mIsPressed; }
    bool IsReleased() const { return mIsReleased; }
    bool IsDown() const { return mIsDown; }
    bool RawDownState() const { return mRawDownState; }

private:
    bool mIsPressed;
    bool mIsReleased;
    bool mIsDown;
    bool mRawDownState;
};
