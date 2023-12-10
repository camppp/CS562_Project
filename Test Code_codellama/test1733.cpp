#include <vector>
#include <iostream>

namespace audio {
    enum class AUDIO_ID {
        MUSIC,
        EFFECTS,
        VOICE
    };

    class AudioManager {
    private:
        std::vector<AUDIO_ID> audioIDs;

    public:
        void addAudioID(AUDIO_ID id) {
            audioIDs.push_back(id);
        }

        void removeAudioID(AUDIO_ID id) {
            auto it = std::find(audioIDs.begin(), audioIDs.end(), id);
            if (it != audioIDs.end()) {
                audioIDs.erase(it);
            }
        }

        std::vector<AUDIO_ID> getAudioIDs() {
            return audioIDs;
        }
    };
}

int main() {
    audio::AudioManager manager;

    // Add audio IDs
    manager.addAudioID(audio::AUDIO_ID::MUSIC);
    manager.addAudioID(audio::AUDIO_ID::EFFECTS);
    manager.addAudioID(audio::AUDIO_ID::VOICE);

    // Remove audio IDs
    manager.removeAudioID(audio::AUDIO_ID::EFFECTS);

    // Get audio IDs
    std::vector<audio::AUDIO_ID> audioIDs = manager.getAudioIDs();
    for (auto id : audioIDs) {
        std::cout << "Audio ID: " << id << std::endl;
    }

    return 0;
}
