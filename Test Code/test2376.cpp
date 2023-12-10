#include <iostream>

class CStrictRange {
private:
    int start;
    int end;

public:
    CStrictRange(int start, int end) : start(start), end(end) {}

    bool contains(int value) {
        return value >= start && value <= end;
    }

    int length() {
        return (end - start) + 1;
    }

    bool isEmpty() {
        return start > end;
    }
};

int main() {
    // Example usage
    CStrictRange range1(1, 5);
    std::cout << "Range contains 3: " << std::boolalpha << range1.contains(3) << std::endl;
    std::cout << "Range length: " << range1.length() << std::endl;
    std::cout << "Range is empty: " << std::boolalpha << range1.isEmpty() << std::endl;

    CStrictRange range2(7, 3);
    std::cout << "Range contains 5: " << std::boolalpha << range2.contains(5) << std::endl;
    std::cout << "Range length: " << range2.length() << std::endl;
    std::cout << "Range is empty: " << std::boolalpha << range2.isEmpty() << std::endl;

    return 0;
}
