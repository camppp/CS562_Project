#include <boost/vmd/is_number.hpp>

#define IS_NUMBER(input) BOOST_VMD_IS_NUMBER(input)

int main() {
    // Test cases
    int result1 = IS_NUMBER(123);  // Should return 1
    int result2 = IS_NUMBER(3.14);  // Should return 1
    int result3 = IS_NUMBER("hello");  // Should return 0
    int result4 = IS_NUMBER(xyz);  // Should return 0

    // Additional test cases
    int result5 = IS_NUMBER(1e3);  // Should return 1 (scientific notation)
    int result6 = IS_NUMBER(0xFF);  // Should return 1 (hexadecimal)
    int result7 = IS_NUMBER(077);  // Should return 1 (octal)

    // Output results
    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
    printf("Result 3: %d\n", result3);
    printf("Result 4: %d\n", result4);
    printf("Result 5: %d\n", result5);
    printf("Result 6: %d\n", result6);
    printf("Result 7: %d\n", result7);

    return 0;
}
