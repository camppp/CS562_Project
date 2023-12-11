#include <iostream>

class OSExchangeData {
  // Implementation details not relevant to the problem
};

class MenuItemView {
public:
  void OnDrag(OSExchangeData* data) {
    // Your implementation here
    std::cout << "OnDrag called" << std::endl;
  }
};

class MenuController {
public:
  void Hide() {
    // Your implementation here
    std::cout << "Hide called" << std::endl;
  }
  static MenuController* GetActiveInstance() {
    // Implementation details not relevant to the problem
    return nullptr;
  }
};

class TestMenuDelegate {
public:
  void WriteDragData(MenuItemView* sender, OSExchangeData* data) {
    // Your implementation here
    std::cout << "WriteDragData called" << std::endl;
  }
};
