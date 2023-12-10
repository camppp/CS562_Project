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

int main() {
    DataContainer container;
    container.setValue(3.14);
    std::cout << "Numerical value: " << container.getValue() << std::endl;
    container.setString("Hello, World!");
    std::cout << "String value: " << container.getString() << std::endl;
    std::cout << "Number of accesses to numerical value: " << container.getNumAccesses() << std::endl;
    return 0;
}
