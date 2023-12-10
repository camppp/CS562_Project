#include <iostream>

class Texture {
 public:
  Texture(const std::string& name) : name_(name) {}
  std::string getName() const { return name_; }

 private:
  std::string name_;
};

class MazeDoor {
 public:
  MazeDoor(Texture* doorTexture) : curObjTexture_(doorTexture) {}
  ~MazeDoor() {}

  void setTexture(Texture* newTexture) { curObjTexture_ = newTexture; }
  Texture* getTexture() { return curObjTexture_; }

  bool isOpen() { return curObjTexture_ != nullptr; }

 private:
  Texture* curObjTexture_;
};

int main() {
  Texture* doorTexture = new Texture("door.png");
  MazeDoor door(doorTexture);

  door.setTexture(doorTexture);
  std::cout << "Door texture: " << door.getTexture()->getName() << std::endl;

  if (door.isOpen()) {
    std::cout << "Door is open" << std::endl;
  } else {
    std::cout << "Door is closed" << std::endl;
  }

  return 0;
}
