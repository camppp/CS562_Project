#include <iostream>
#include <unordered_map>

class SoundSystem {
private:
    std::unordered_map<std::string, std::unordered_map<int, std::string>> activeSounds;

public:
    void EmitSound(const std::string& entityName, int channel, const std::string& sample, float volume, float attenuation) {
        // Logic to emit the sound for the given entity, channel, sample, volume, and attenuation
        // Add the sound to the activeSounds map
        activeSounds[entityName][channel] = sample;
        std::cout << "Emitting sound for entity: " << entityName << ", channel: " << channel << ", sample: " << sample << std::endl;
    }

    void StopSound(const std::string& entityName, int channel, const std::string& sample) {
        // Logic to stop the specified sound for the given entity and channel
        // Remove the sound from the activeSounds map
        if (activeSounds.count(entityName) && activeSounds[entityName].count(channel) && activeSounds[entityName][channel] == sample) {
            activeSounds[entityName].erase(channel);
            std::cout << "Stopping sound for entity: " << entityName << ", channel: " << channel << ", sample: " << sample << std::endl;
        }
    }

    void EmitSuitSound(const std::string& entityName, const std::string& sample) {
        // Logic to play the suit-specific sound for the given entity
        // This method is specific to playing suit sounds
        std::cout << "Playing suit sound for entity: " << entityName << ", sample: " << sample << std::endl;
    }
};

int main() {
    SoundSystem soundSystem;
    soundSystem.EmitSound("Player1", 1, "gunshot.wav", 0.8f, 0.5f);
    soundSystem.EmitSuitSound("Player1", "suitvoice.wav");
    soundSystem.StopSound("Player1", 1, "gunshot.wav");
    return 0;
}
