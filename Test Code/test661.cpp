#include <iostream>

enum DisplayPowerState {
  DISPLAY_POWER_ALL_ON,
  DISPLAY_POWER_DIMMED,
  DISPLAY_POWER_OFF
};

class ExternalBacklightController {
public:
  double screenBrightnessPercent = 47.0;
  int numUserAdjustments = 2;
  DisplayPowerState displayPowerState = DISPLAY_POWER_ALL_ON;

  void CallDecreaseScreenBrightness(bool allow_off) {
    if (allow_off) {
      screenBrightnessPercent -= 5.0;
    } else {
      screenBrightnessPercent -= 3.0;
    }
    numUserAdjustments++;
    UpdateDisplayPowerState();
  }

  void UpdateDisplayPowerState() {
    if (screenBrightnessPercent <= 0.0) {
      displayPowerState = DISPLAY_POWER_OFF;
    } else if (screenBrightnessPercent < 47.0) {
      displayPowerState = DISPLAY_POWER_DIMMED;
    } else {
      displayPowerState = DISPLAY_POWER_ALL_ON;
    }
  }
};

void AdjustScreenBrightness(ExternalBacklightController& controller, bool allow_off) {
  controller.CallDecreaseScreenBrightness(allow_off);
}

int main() {
  ExternalBacklightController controller;
  std::cout << "Initial Screen Brightness: " << controller.screenBrightnessPercent << std::endl;
  std::cout << "Initial User Adjustments: " << controller.numUserAdjustments << std::endl;
  std::cout << "Initial Display Power State: " << controller.displayPowerState << std::endl;

  AdjustScreenBrightness(controller, true);  // Simulate decrease with allow_off as true

  std::cout << "Updated Screen Brightness: " << controller.screenBrightnessPercent << std::endl;
  std::cout << "Updated User Adjustments: " << controller.numUserAdjustments << std::endl;
  std::cout << "Updated Display Power State: " << controller.displayPowerState << std::endl;

  return 0;
}
