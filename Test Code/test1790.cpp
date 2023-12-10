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

  std::string operation = argv[1];
  std::string input_file = argv[2];
  std::string output_file = argv[3];

  AudioFile audio(input_file);
  if (!audio.isValid())
  {
    std::cerr << "Error: Unable to open input file" << std::endl;
    return 1;
  }

  if (operation == "normalize")
  {
    audio.normalize();
  }
  else if (operation == "reverse")
  {
    audio.reverse();
  }
  else if (operation == "fade")
  {
    audio.fade();
  }
  else
  {
    std::cerr << "Error: Unsupported operation" << std::endl;
    return 1;
  }

  if (!audio.save(output_file))
  {
    std::cerr << "Error: Unable to save output file" << std::endl;
    return 1;
  }

  std::cout << "Audio processing completed successfully" << std::endl;
  return 0;
}
