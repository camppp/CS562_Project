#include <iostream>
#include <string>

class DataContainer {
private:
    double mValue;
    std::string mString;
    mutable int mNumAccesses = 0;

public:
    void setValue(double value) {
        mValue = value;
    }

    double getValue() const {
        mNumAccesses++;  // Increment the number of accesses
        return mValue;
    }

    void setString(const std::string& str) {
        mString = str;
    }

    std::string getString() const {
        return mString;
    }

    int getNumAccesses() const {
        return mNumAccesses;
    }
};
