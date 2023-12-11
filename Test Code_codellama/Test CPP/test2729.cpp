#include <fmod.hpp>

class AudioSourceBase {
public:
    virtual void stop() = 0;
};

class AudioManager {
public:
    void remove(AudioSourceBase* source) {
        // Remove the source from the manager
    }

    void play(AudioSourceBase* source) {
        // Play the source
    }

    void stop(AudioSourceBase* source) {
        // Stop the source
    }
};

class FMODSource : public AudioSourceBase {
public:
    FMODSource(const char* filename) {
        // Initialize the FMOD source
    }

    void stop() override {
        // Stop the FMOD source
    }
};

int main() {
    // Create an FMOD source
    FMODSource* source = new FMODSource("audio.wav");

    // Create an audio manager
    AudioManager manager;

    // Add the source to the manager
    manager.add(source);

    // Play the source
    manager.play(source);

    // Stop the source
    manager.stop(source);

    // Remove the source from the manager
    manager.remove(source);

    return 0;
}
