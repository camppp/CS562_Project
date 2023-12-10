class CurveDeleteKeysAction {
public:
    CurveDeleteKeysAction(const std::vector<Curve::Key>& keys) : keys_(keys) {}

    void Redo() {
        for (const auto& key : keys_) {
            // Remove the key from the curve editor
            curveEditor.RemoveKey(key.position, key.value);
        }
    }

private:
    std::vector<Curve::Key> keys_;
};
