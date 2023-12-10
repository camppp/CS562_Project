class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    int increment(int value) {
        count += value; // Complete implementation to increment count by the given value
        return count;   // Return the updated value of count
    }
};
