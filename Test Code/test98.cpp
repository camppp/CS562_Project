bool Engine::CreateReality(const Layout& layout) {
  if (layout.lreality != nullptr && layout.lrenderer != nullptr) {
    layout.lreality->lrenderer = layout.lrenderer;
    return true; // Initialization successful
  } else {
    return false; // Initialization failed due to missing components
  }
}
