int VLCPlayer::resume() {
    if (mp == nullptr) {
        return -1;
    }

    // Resume the playback of the media file
    libvlc_media_player_play(mp);

    return 0;
}
