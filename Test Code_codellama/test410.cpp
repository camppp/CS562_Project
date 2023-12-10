class KeyState {
public:
    KeyState() : mIsPressed(false), mIsReleased(false), mIsDown(false), mRawDownState(false) {}

    bool IsPressed() const { return mIsPressed; }
    bool IsReleased() const { return mIsReleased; }
    bool IsDown() const { return mIsDown; }
    bool RawDownState() const { return mRawDownState; }

    void SetPressed(bool isPressed) { mIsPressed = isPressed; }
    void SetReleased(bool isReleased) { mIsReleased = isReleased; }
    void SetDown(bool isDown) { mIsDown = isDown; }
    void SetRawDownState(bool rawDownState) { mRawDownState = rawDownState; }

private:
    bool mIsPressed;
    bool mIsReleased;
    bool mIsDown;
    bool mRawDownState;
};
