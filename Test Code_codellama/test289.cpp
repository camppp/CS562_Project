class CombinedSignal {
public:
    virtual double calculateCombinedValue(const Signal& signal1, const Signal& signal2) = 0;
};

class DifferenceCombinedSignal : public CombinedSignal {
public:
    double calculateCombinedValue(const Signal& signal1, const Signal& signal2) override {
        return signal1.getValue() - signal2.getValue();
    }
};
