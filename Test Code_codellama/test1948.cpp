c
bool isAudioTrack(int track) {
    // Check if the track number is within the valid range
    if (track < 0 || track >= MAX_TRACKS) {
        printf("Track %d is not audio\n", track);
        return FALSE;
    }

    // Check if the track is an audio track
    if (track % 2 == 0) {
        return TRUE;
    } else {
        printf("Track %d is not audio\n", track);
        return FALSE;
    }
}
