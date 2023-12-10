#include <stdio.h>

int main() {
    int a = 10;
    float b = 3.14;
    char c = 'a';
    double d = 3.14159;

    printf("Address of a: %p\n", &a);
    printf("Value of a: %d\n", a);

    printf("Address of b: %p\n", &b);
    printf("Value of b: %f\n", b);

    printf("Address of c: %p\n", &c);
    printf("Value of c: %c\n", c);

    printf("Address of d: %p\n", &d);
    printf("Value of d: %f\n", d);

    return 0;
}
