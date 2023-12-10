void MixAudioCbk(void* userdata, Uint8* stream, int len) {
    // Get the game engine instance from the user data
    GameEngine* engine = (GameEngine*)userdata;

    // Get the audio format from the game engine
    AudioFormat fmt = engine->getAudioFormat();

    // Mix the audio samples based on the game's audio requirements
    for (int i = 0; i < len; i++) {
        stream[i] = (Uint8)((stream[i] * 0.5) + (fmt.sample * 0.5));
    }
}
