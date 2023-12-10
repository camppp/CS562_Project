c
#include <stdbool.h>

bool palindrome(int arr[], int size) {
    bool isPalindrome = true;
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}
