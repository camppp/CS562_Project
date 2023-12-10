#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* numberN, char* numberM) {
    int n = strlen(numberN), m = strlen(numberM);
    int maxLen = (n > m) ? n : m;
    int carry = 0;
    char* result = (char*)malloc((maxLen + 2) * sizeof(char)); // +2 for potential carry and null terminator
    result[maxLen + 1] = '\0'; // null terminator

    for (int i = 0; i < maxLen; i++) {
        int digitN = (i < n) ? numberN[n - 1 - i] - '0' : 0;
        int digitM = (i < m) ? numberM[m - 1 - i] - '0' : 0;
        int sum = digitN + digitM + carry;
        result[maxLen - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result[0] = carry + '0';
        return result;
    } else {
        return result + 1; // skip the first character (potential leading zero)
    }
}

int main() {
    char numberN[1500], numberM[1500];
    scanf("%s%s", numberN, numberM);
    char* sum = addStrings(numberN, numberM);
    printf("%s\n", sum);
    free(sum); // free the allocated memory
    return 0;
}
