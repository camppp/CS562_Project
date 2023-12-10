class SoundSystem {
public:
    // Constructor
    SoundSystem() {
        // Initialize the sound system
        // ...
    }

    // Emit a sound
    void EmitSound(const std::string& entityName, int channel, const std::string& sample, float volume, float attenuation) {
        // ...
    }

    // Stop a sound
    void StopSound(const std::string& entityName, int channel, const std::string& sample) {
        // ...
    }

    // Play a suit-specific sound
    void EmitSuitSound(const std::string& entityName, const std::string& sample) {
        // ...
    }

private:
    // Data structures for managing emitted sounds
    std::map<std::string, std::vector<Sound>> sounds;
    std::map<std::string, std::vector<Sound>> suitsounds;

    // Function to play a sound
    void PlaySound(const std::string& entityName, int channel, const std::string& sample) {
        // ...
    }

    // Function to stop a sound
    void StopSound(const std::string& entityName, int channel, const std::string& sample) {
        // ...
    }
};
