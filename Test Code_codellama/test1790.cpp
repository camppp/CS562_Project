#include <iostream>
#include "audio_processing.h"

using namespace maolan::audio;

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "Usage: " << argv[0] << " <operation> <input_file> <output_file>" << std::endl;
    return 1;
  }

  // Parse command-line arguments
  std::string operation = argv[1];
  std::string input_file = argv[2];
  std::string output_file = argv[3];

  // Perform audio processing operation
  if (operation == "normalize")
  {
    // Normalize the audio to a standard amplitude level
    AudioFile input_audio(input_file);
    AudioFile output_audio(output_file);
    Normalize(input_audio, output_audio);
  }
  else if (operation == "reverse")
  {
    // Reverse the audio samples
    AudioFile input_audio(input_file);
    AudioFile output_audio(output_file);
    Reverse(input_audio, output_audio);
  }
  else if (operation == "fade")
  {
    // Apply a fade-in and fade-out effect to the audio
    AudioFile input_audio(input_file);
    AudioFile output_audio(output_file);
    Fade(input_audio, output_audio);
  }
  else
  {
    std::cerr << "Invalid operation: " << operation << std::endl;
    return 1;
  }

  return 0;
}
