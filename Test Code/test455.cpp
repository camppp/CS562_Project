void UiSceneCreator::CreateControllers() {
  if (IsAndroidPlatform()) {
    auto root = std::make_unique<UiElement>();
    root->SetName(kControllerRoot);

    // Create and add UI controllers specific to Android platform
    auto androidController1 = std::make_unique<UiControllerAndroid1>();
    root->AddChild(std::move(androidController1));

    auto androidController2 = std::make_unique<UiControllerAndroid2>();
    root->AddChild(std::move(androidController2));

    // Add the root element to the UI scene
    AddRootElement(std::move(root));
  }
}
