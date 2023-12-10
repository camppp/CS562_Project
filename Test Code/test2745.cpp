#include <iostream>

enum class MusicState { SPK_NONE, SPK_PLAYING, SPK_PAUSED };

class MusicEmitter {
public:
    void play() {
        std::cout << "Music is now playing." << std::endl;
    }

    void pause() {
        std::cout << "Music is now paused." << std::endl;
    }

    void stop() {
        std::cout << "Music playback stopped." << std::endl;
    }
};

class Speaker {
private:
    MusicEmitter* emitter;
    MusicState state;

public:
    Speaker(MusicEmitter* musicEmitter) : emitter(musicEmitter), state(MusicState::SPK_NONE) {}

    void play() {
        if (state != MusicState::SPK_PLAYING) {
            state = MusicState::SPK_PLAYING;
            emitter->play();
        }
    }

    void pause() {
        if (state == MusicState::SPK_PLAYING) {
            state = MusicState::SPK_PAUSED;
            emitter->pause();
        }
    }

    void stop() {
        state = MusicState::SPK_NONE;
        emitter->stop();
    }

    void onScenePause() {
        if (state == MusicState::SPK_PLAYING) {
            pause();
        }
    }

    void onSceneResume() {
        switch (state) {
            case MusicState::SPK_PAUSED:
                play();
                break;
            case MusicState::SPK_NONE:
                // Handle the case when the music should start playing automatically on scene resume
                break;
            default:
                // Do nothing if the music is already playing
                break;
        }
    }
};

int main() {
    MusicEmitter musicEmitter;
    Speaker speaker(&musicEmitter);

    speaker.play();  // Output: Music is now playing.
    speaker.pause(); // Output: Music is now paused.
    speaker.stop();  // Output: Music playback stopped.

    return 0;
}
