#include <stdio.h>
#include <stdlib.h>

char* formatTime(int ms) {
    int days = ms / (1000 * 60 * 60 * 24);
    int hours = (ms % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60);
    int minutes = (ms % (1000 * 60 * 60)) / (1000 * 60);
    int seconds = (ms % (1000 * 60)) / 1000;
    int milliseconds = ms % 1000;

    char* result = (char*)malloc(100);
    sprintf(result, "%d:%02d:%02d:%02d.%03d", days, hours, minutes, seconds, milliseconds);

    return result;
}
