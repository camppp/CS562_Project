#include <iostream>

enum SpeakerState {
    SPK_NONE,
    SPK_PLAYING,
    SPK_PAUSED
};

class Speaker {
private:
    MusicEmitter* emitter;
    SpeakerState state;

public:
    Speaker(MusicEmitter* emitter) : emitter(emitter), state(SPK_NONE) {}

    void play() {
        if (state == SPK_NONE) {
            emitter->play();
            state = SPK_PLAYING;
        }
    }

    void pause() {
        if (state == SPK_PLAYING) {
            emitter->pause();
            state = SPK_PAUSED;
        }
    }

    void stop() {
        if (state == SPK_PLAYING || state == SPK_PAUSED) {
            emitter->stop();
            state = SPK_NONE;
        }
    }

    void onScenePause() {
        if (state == SPK_PLAYING) {
            pause();
        }
    }

    void onSceneResume() {
        if (state == SPK_PAUSED) {
            play();
        }
    }
};
