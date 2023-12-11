class CStrictRange {
public:
    CStrictRange(int start, int end) {
        this->start = start;
        this->end = end;
    }

    bool contains(int value) {
        return (start <= value && value <= end);
    }

    int length() {
        return end - start + 1;
    }

    bool isEmpty() {
        return start > end;
    }

private:
    int start;
    int end;
};
