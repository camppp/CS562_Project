class PowerStateObserver {
 public:
  void GeneratePowerStateEvent(bool isOnBattery) {
    if (isOnBattery != lastPowerState_) {
      powerStateChanges_++;
      lastPowerState_ = isOnBattery;
    }
  }

  int powerStateChanges() const { return powerStateChanges_; }

  bool lastPowerState() const { return lastPowerState_; }

 private:
  int powerStateChanges_ = 0;
  bool lastPowerState_ = false;
};
