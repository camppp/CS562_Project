#include <iostream>
#include <string>

class Sound {
private:
    std::string filePath;
    bool isPlaying;
    int volume;

public:
    Sound(const std::string& filePath) : filePath(filePath), isPlaying(false), volume(50) {
        // Load the sound file from the given file path
        std::cout << "Sound file loaded from: " << filePath << std::endl;
    }

    void play() {
        if (!isPlaying) {
            std::cout << "Playing sound file: " << filePath << std::endl;
            isPlaying = true;
        } else {
            std::cout << "Sound file is already playing" << std::endl;
        }
    }

    void stop() {
        if (isPlaying) {
            std::cout << "Stopping sound file: " << filePath << std::endl;
            isPlaying = false;
        } else {
            std::cout << "No sound file is currently playing" << std::endl;
        }
    }

    void setVolume(int newVolume) {
        if (newVolume >= 0 && newVolume <= 100) {
            volume = newVolume;
            std::cout << "Volume set to: " << volume << std::endl;
        } else {
            std::cout << "Volume level should be between 0 and 100" << std::endl;
        }
    }
};

int main() {
    Sound sound("example_sound.wav");
    sound.play();
    sound.setVolume(75);
    sound.stop();
    return 0;
}
