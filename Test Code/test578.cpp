#include <math.h>

#define MAX_VOLUME 100

typedef struct {
    float x;
    float y;
    float z;
} vec;

float calculate_distance(const vec *loc) {
    // Assuming listener's location is at (0, 0, 0)
    return sqrt(loc->x * loc->x + loc->y * loc->y + loc->z * loc->z);
}

void sound_updatechanvol(int chan, const vec *loc) {
    float distance = calculate_distance(loc);
    int volume = MAX_VOLUME - distance;
    if (volume < 0) {
        volume = 0;
    }
    // Update the volume of the specified channel
    // Code to update the volume of the specified channel goes here
}
