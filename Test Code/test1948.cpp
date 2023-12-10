#include <stdio.h>
#include <stdbool.h>

bool isAudioTrack(int track) {
    // Assuming audio tracks are numbered from 1 to 100
    if (track >= 1 && track <= 100) {
        // Logic to determine if the track is an audio track
        // For example, if audio tracks are numbered from 1 to 50
        if (track <= 50) {
            return true;  // Track is an audio track
        } else {
            printf("Track %d is not audio\n", track);
            return false;  // Track is not an audio track
        }
    } else {
        printf("Invalid track number\n");
        return false;  // Invalid track number
    }
}
