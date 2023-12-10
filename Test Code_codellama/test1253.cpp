#include <iostream>
#include <SDL.h>

class KeyboardInput {
private:
  static bool created;
  static KeyboardInput* instance;

public:
  KeyboardInput() {
    if (created) {
      Logger::error("Cannot create more than 1 KeyboardInput");
      abort();
    }
    created = true;
    instance = this;
  }

  const Uint8* getKeyboardState() {
    int length;
    return SDL_GetKeyboardState(&length);
  }

  static KeyboardInput* getInstance() {
    if (!instance) {
      instance = new KeyboardInput();
    }
    return instance;
  }
};

bool KeyboardInput::created = false;
KeyboardInput* KeyboardInput::instance = nullptr;

int main() {
  KeyboardInput* keyboard = KeyboardInput::getInstance();
  const Uint8* keyboardState = keyboard->getKeyboardState();
  // Use keyboardState to process keyboard input
  return 0;
}
