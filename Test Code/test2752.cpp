class TripleMirrorFreqN {
public:
    TripleMirrorFreqN(int value) : value_(value) {}

    int getFrequency(const std::vector<int>& list) {
        int frequency = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == value_) {
                frequency++;
            }
        }
        return frequency;
    }

    int getMirroredFrequency(const std::vector<int>& list) {
        int frequency = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == value_) {
                frequency++;
            }
        }
        return frequency;
    }

private:
    int value_;
};
