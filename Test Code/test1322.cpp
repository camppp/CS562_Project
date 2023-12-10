int VLCPlayer::resume()
{
    if(mp==nullptr) return -1;
    libvlc_media_player_set_pause(mp,0); // Resume playback by setting pause to 0

    return 0;
}
