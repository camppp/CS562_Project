bool IsArcAppWindow(aura::Window* window) {
  if (!window) {
    return false;
  }

  // Check if the window is associated with an ARC app by checking the
  // aura::client::kAppType property.
  int app_type = window->GetProperty(aura::client::kAppType);
  if (app_type == static_cast<int>(ash::AppType::ARC_APP)) {
    return true;
  }

  // If the window is not associated with an ARC app, check if it is a
  // transient child of an ARC app window.
  aura::Window* parent = window->GetParent();
  while (parent) {
    if (IsArcAppWindow(parent)) {
      return true;
    }
    parent = parent->GetParent();
  }

  return false;
}
