#include <stdbool.h>
#include <stdio.h>

int myFront = 0;
int myBack = 0;

bool palindrome(int arr[], int size) {
    bool isPalindrome = true;
    for (int i = myFront; i < (myFront + myBack) / 2; i++) {
        if (arr[i] != arr[myBack - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}

int main() {
    int arr1[] = {1, 2, 3, 2, 1};
    int arr2[] = {1, 2, 3, 4, 5};

    bool result1 = palindrome(arr1, 5);
    bool result2 = palindrome(arr2, 5);

    printf("arr1 is a palindrome: %s\n", result1 ? "true" : "false");
    printf("arr2 is a palindrome: %s\n", result2 ? "true" : "false");

    return 0;
}
