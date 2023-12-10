#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("alphabet");
    else if (ch >= '0' && ch <= '9')
        printf("digit");
    else
        printf("special symbol");
    return 0;
}
