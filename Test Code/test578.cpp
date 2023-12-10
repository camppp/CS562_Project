#include <cmath>

const float MAX_VOLUME = 1.0f;

void sound_updatechanvol(int chan, const Vector* loc) {
    // Calculate the distance between the sound source and the listener
    float distance = sqrt(pow(loc->x - listener_x, 2) + pow(loc->y - listener_y, 2) + pow(loc->z - listener_z, 2));

    // Calculate the volume based on the distance
    float volume = MAX_VOLUME - distance;

    // Handle the case where the distance is greater than the maximum volume level
    if (volume < 0) {
        volume = 0;
    }

    // Update the volume of the specified sound channel
    sound_setchanvol(chan, volume);
}
