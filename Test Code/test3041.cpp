#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  // Check if the number of arguments is correct
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <channel_id>" << std::endl;
    return 1;
  }

  // Extract the channel ID from the command-line arguments
  std::string channel_id = argv[1];

  // Print the ThingSpeak write fields message
  std::cout << "ThingSpeak write fields, Channel Id: " << channel_id << std::endl;

  return 0;
}
