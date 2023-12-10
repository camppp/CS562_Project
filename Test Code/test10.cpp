#include <stdio.h>

int main() {
    int i = 10;
    float f = 3.14;
    char ch = 'A';
    double d = 123.456;

    printf("Address of i: %p\n", (void*)&i);
    printf("Value of i: %d\n\n", i);

    printf("Address of f: %p\n", (void*)&f);
    printf("Value of f: %f\n\n", f);

    printf("Address of ch: %p\n", (void*)&ch);
    printf("Value of ch: %c\n\n", ch);

    printf("Address of d: %p\n", (void*)&d);
    printf("Value of d: %lf\n\n", d);

    return 0;
}
