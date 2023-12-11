#include <iostream>

int Sum(int a, int b) {
    return a + b;
}

TEST(SumTest, TestSum) {
    LONGS_EQUAL(8, Sum(3, 5));
}
