ShelfAutoHideBehavior AutoHideBehaviorFromPref(const std::string& pref) {
  if (pref == kShelfAutoHideBehaviorAlways) {
    return SHELF_AUTO_HIDE_BEHAVIOR_ALWAYS;
  } else if (pref == kShelfAutoHideBehaviorNever) {
    return SHELF_AUTO_HIDE_BEHAVIOR_NEVER;
  } else {
    return SHELF_AUTO_HIDE_BEHAVIOR_ALWAYS;
  }
}

std::string AutoHideBehaviorToPref(ShelfAutoHideBehavior behavior) {
  switch (behavior) {
    case SHELF_AUTO_HIDE_BEHAVIOR_ALWAYS:
      return kShelfAutoHideBehaviorAlways;
    case SHELF_AUTO_HIDE_BEHAVIOR_NEVER:
      return kShelfAutoHideBehaviorNever;
    default:
      return kShelfAutoHideBehaviorAlways;
  }
}
