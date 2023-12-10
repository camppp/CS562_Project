#include <iostream>
#include <SDL.h>

class Logger {
public:
  static void error(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
  }
};

class KeyboardInput {
private:
  static bool created;

public:
  KeyboardInput() {
    if (created) {
      Logger::error("Cannot create more than 1 KeyboardInput");
      abort();
    }
    created = true;
  }

  const Uint8* getKeyboardState() {
    int length;
    return SDL_GetKeyboardState(&length);
  }
};

bool KeyboardInput::created = false;

int main() {
  KeyboardInput keyboard;
  const Uint8* keyboardState = keyboard.getKeyboardState();
  // Use keyboardState to process keyboard input
  return 0;
}
