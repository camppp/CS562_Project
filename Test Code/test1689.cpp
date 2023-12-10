#include <iostream>

class PowerStateObserver {
private:
    int powerStateChanges;
    bool lastPowerState;

public:
    PowerStateObserver() : powerStateChanges(0), lastPowerState(false) {}

    void GeneratePowerStateEvent(bool isOnBattery) {
        if (isOnBattery != lastPowerState) {
            powerStateChanges++;
            lastPowerState = isOnBattery;
        }
    }

    int power_state_changes() const {
        return powerStateChanges;
    }

    bool last_power_state() const {
        return lastPowerState;
    }
};

int main() {
    PowerStateObserver observers[1];
    observers[0].GeneratePowerStateEvent(true);
    std::cout << "Power state changes: " << observers[0].power_state_changes() << std::endl;  // Output: 1
    std::cout << "Last power state: " << std::boolalpha << observers[0].last_power_state() << std::endl;  // Output: true

    // Repeated indications the device is on battery power should be suppressed.
    observers[0].GeneratePowerStateEvent(true);
    std::cout << "Power state changes: " << observers[0].power_state_changes() << std::endl;  // Output: 1
    return 0;
}
