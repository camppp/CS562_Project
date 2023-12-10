class Population {
private:
    bool mIsParsed;
    int mYear;
    long mTotalPop;

public:
    Population() : mIsParsed(false), mYear(0), mTotalPop(0) {}

    void setYearAndTotalPop(int year, long totalPop) {
        mIsParsed = true;
        mYear = year;
        mTotalPop = totalPop;
    }

    int getYear() const {
        return mYear;
    }

    long getTotalPop() const {
        return mTotalPop;
    }
};
