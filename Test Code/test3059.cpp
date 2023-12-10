#include <iostream>
#include <string>

// Define a struct to hold the audio information
struct AudioInfo {
  int samplingFrequency;
  int extendedSamplingFrequency;
  int numChannels;
  int objectType;
};

// Function to parse and extract audio information from the audio header
AudioInfo parseAudioHeader(const AudioHeader& audio_header) {
  // Extract properties from the audio header
  int samplingFrequency = audio_header.GetSamplingFrequency();
  int extendedSamplingFrequency = audio_header.GetExtendedSamplingFrequency();
  int numChannels = audio_header.GetNumChannels();
  int objectType = audio_header.GetObjectType();

  // Create an AudioInfo object with the extracted properties
  AudioInfo audioInfo = {samplingFrequency, extendedSamplingFrequency, numChannels, objectType};
  return audioInfo;
}

int main() {
  // Example usage of parseAudioHeader function
  AudioHeader audio_header(/* initialize audio header */);
  AudioInfo audioInfo = parseAudioHeader(audio_header);

  // Output the extracted audio information
  std::cout << "Sampling frequency: " << audioInfo.samplingFrequency << std::endl;
  std::cout << "Extended sampling frequency: " << audioInfo.extendedSamplingFrequency << std::endl;
  std::cout << "Number of channels: " << audioInfo.numChannels << std::endl;
  std::cout << "Object type: " << audioInfo.objectType << std::endl;

  return 0;
}
