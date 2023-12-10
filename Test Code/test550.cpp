#include <stdio.h>
#include <stdlib.h>

char* formatTime(int ms) {
    int day = ms / (24 * 60 * 60 * 1000);
    ms %= (24 * 60 * 60 * 1000);
    int hour = ms / (60 * 60 * 1000);
    ms %= (60 * 60 * 1000);
    int minute = ms / (60 * 1000);
    ms %= (60 * 1000);
    int second = ms / 1000;
    ms %= 1000;

    char* result = (char*)malloc(20 * sizeof(char)); // Allocate memory for the result string
    sprintf(result, "%d:%02d:%02d:%02d.%03d", day, hour, minute, second, ms);
    return result;
}

int main() {
    int input = 123456789;
    char* formattedTime = formatTime(input);
    printf("Formatted time: %s\n", formattedTime);
    free(formattedTime); // Free the allocated memory
    return 0;
}
