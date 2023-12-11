#include <stdio.h>

int main() {
    // Declare and initialize variables
    int a = 10;
    float b = 20.5;
    char c = 'A';
    double d = 30.75;

    // Print the address and value of each variable
    printf("Address of a: %p Value of a: %d\n", &a, a);
    printf("Address of b: %p Value of b: %f\n", &b, b);
    printf("Address of c: %p Value of c: %c\n", &c, c);
    printf("Address of d: %p Value of d: %lf\n", &d, d);

    return 0;
}