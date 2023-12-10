#include <iostream>
#include <vector>

namespace mv
{
  namespace constants
  {
    namespace audio
    {
      enum class AUDIO_ID
      {
        SOUNDTRACK,
        EFFECT1,
        EFFECT2
      };
    }
  }
}

class AudioManager
{
private:
  std::vector<mv::constants::audio::AUDIO_ID> audioIDs;

public:
  void addAudioID(mv::constants::audio::AUDIO_ID id)
  {
    audioIDs.push_back(id);
  }

  void removeAudioID(mv::constants::audio::AUDIO_ID id)
  {
    audioIDs.erase(std::remove(audioIDs.begin(), audioIDs.end(), id), audioIDs.end());
  }

  std::vector<mv::constants::audio::AUDIO_ID> getAudioIDs()
  {
    return audioIDs;
  }
};

int main()
{
  AudioManager audioManager;
  
  // Adding audio IDs
  audioManager.addAudioID(mv::constants::audio::AUDIO_ID::SOUNDTRACK);
  audioManager.addAudioID(mv::constants::audio::AUDIO_ID::EFFECT1);
  audioManager.addAudioID(mv::constants::audio::AUDIO_ID::EFFECT2);

  // Removing an audio ID
  audioManager.removeAudioID(mv::constants::audio::AUDIO_ID::EFFECT1);

  // Retrieving all audio IDs
  std::vector<mv::constants::audio::AUDIO_ID> allAudioIDs = audioManager.getAudioIDs();
  std::cout << "All Audio IDs: ";
  for (auto id : allAudioIDs)
  {
    std::cout << static_cast<int>(id) << " ";
  }
  std::cout << std::endl;

  return 0;
}
