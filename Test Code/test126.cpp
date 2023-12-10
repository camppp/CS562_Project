#include <string>

enum ShelfAutoHideBehavior {
  SHELF_AUTO_HIDE_BEHAVIOR_ALWAYS,
  SHELF_AUTO_HIDE_BEHAVIOR_NEVER
};

const std::string kShelfAutoHideBehaviorAlways = "Always";

ShelfAutoHideBehavior AutoHideBehaviorFromPref(const std::string& value) {
  // Note: To maintain sync compatibility with old images of chrome/chromeos
  // the set of values that may be encountered includes the now-extinct
  // "Default" as well as "Never" and "Always", "Default" should now
  // be treated as "Never" (http://crbug.com/146773).
  if (value == kShelfAutoHideBehaviorAlways)
    return SHELF_AUTO_HIDE_BEHAVIOR_ALWAYS;
  return SHELF_AUTO_HIDE_BEHAVIOR_NEVER;
}

const char* AutoHideBehaviorToPref(ShelfAutoHideBehavior behavior) {
  switch (behavior) {
    case SHELF_AUTO_HIDE_BEHAVIOR_ALWAYS:
      return kShelfAutoHideBehaviorAlways.c_str();
    case SHELF_AUTO_HIDE_BEHAVIOR_NEVER:
      return "Never";
    default:
      return "Unknown";
  }
}
