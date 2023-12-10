enum DIRECTION { UP, DOWN, LEFT, RIGHT };
enum StatusFocus { StatusFocusOnTabIndex, StatusFocusOnStatus };

class StatusWidget {
  int currentTabIndex;
  StatusFocus focus;

public:
  void onDirectionKey(DIRECTION dir) {
    switch (dir) {
      case UP:
        switch (focus) {
          case StatusFocusOnTabIndex:
            if (currentTabIndex > 0) {
              currentTabIndex--;
              updateDisplay();
            }
            break;
          case StatusFocusOnStatus:
            // Handle UP direction when focus is on status
            // (Optional based on the specific requirements)
            break;
        }
        break;
      // Handle other directional key cases (DOWN, LEFT, RIGHT)
      // (Optional based on the specific requirements)
    }

    void updateDisplay() {
      // Update the display with the status of the current tab index
      // For example, if the status information is stored in an array
      // named tabStatus, the updateDisplay method could be implemented as follows:
      std::cout << "Current status: " << tabStatus[currentTabIndex] << std::endl;
    }
};
