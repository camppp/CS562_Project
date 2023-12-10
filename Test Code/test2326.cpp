javascript
class GameSettingsManager {
  constructor() {
    this.settings = new Map();
  }

  SetDefNum(key, value, enforceConstraint) {
    this.settings.set(key, { value, enforceConstraint });
  }

  SetMaxAmount(value) {
    // Check if the parameter exists and enforce the constraint if specified
    for (const [key, setting] of this.settings) {
      if (setting.enforceConstraint) {
        if (value < setting.value) {
          return false; // Constraint violation, return false
        }
      }
    }
    return true; // All constraints satisfied, set the maximum amount
  }
}

// Usage
const manager = new GameSettingsManager();
manager.SetDefNum('IBC_BONUSSKILL5AMT', 10, false);
manager.SetDefNum('IBC_LIFESPAN', 100, true);
manager.SetMaxAmount(150); // Returns true
manager.SetMaxAmount(90); // Returns false
