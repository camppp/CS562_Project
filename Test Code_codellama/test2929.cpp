#include <iostream>
#include <string>

class AudioImpl {
public:
    void Finalize();
    bool LoadSE(const char* id, const char* filename);

private:
    // Map of sound effect IDs to their associated audio resources
    std::map<std::string, AudioResource*> seMap;
};

void AudioImpl::Finalize() {
    // Release all audio resources
    for (auto& [id, resource] : seMap) {
        delete resource;
    }
    seMap.clear();
}

bool AudioImpl::LoadSE(const char* id, const char* filename) {
    // Load the sound effect from the file
    AudioResource* resource = LoadAudioResource(filename);
    if (resource == nullptr) {
        std::cerr << "Failed to load sound effect: " << filename << std::endl;
        return false;
    }

    // Add the sound effect to the map
    seMap[id] = resource;
    return true;
}
