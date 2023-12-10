class IntegerNumeral {
private:
    int value;

public:
    // Default constructor
    IntegerNumeral() : value(0) {}

    // Constructor with unsigned short parameter
    IntegerNumeral(unsigned short value) : value(value) {}

    // Constructor with signed short parameter
    IntegerNumeral(signed short value) : value(value) {}

    // Constructor with unsigned long parameter
    IntegerNumeral(unsigned long value) : value(value) {}

    // Default copy constructor
    IntegerNumeral(const IntegerNumeral& other) : value(other.value) {}

    // Default move constructor
    IntegerNumeral(IntegerNumeral&& other) : value(other.value) {}

    // Copy assignment operator
    IntegerNumeral& operator=(const IntegerNumeral& other) {
        value = other.value;
        return *this;
    }

    // Move assignment operator
    IntegerNumeral& operator=(IntegerNumeral&& other) {
        value = other.value;
        return *this;
    }

    // Getter function for the value
    int getValue() const {
        return value;
    }
};
