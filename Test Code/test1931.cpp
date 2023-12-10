class OSExchangeData {
  // Implementation details not relevant to the problem
};

class MenuItemView {
public:
  void OnDrag(OSExchangeData* data) {
    // Handle drag-and-drop functionality for the menu item
    // Implementation details not provided
  }
};

class MenuController {
public:
  void Hide() {
    // Hide the menu controller
    MenuController* controller = MenuController::GetActiveInstance();
    if (!controller)
      return;
    // Implementation details not provided
  }
  static MenuController* GetActiveInstance() {
    // Implementation details not relevant to the problem
    return nullptr;
  }
};

class TestMenuDelegate {
public:
  void WriteDragData(MenuItemView* sender, OSExchangeData* data) {
    // Write drag data for the menu item
    // Implementation details not provided
  }
};
