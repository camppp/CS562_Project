void UiSceneCreator::CreateControllers()
{
    // Check if the platform is Android
    if (IsAndroidPlatform())
    {
        // Create a root element for the controllers
        UiElement* kControllerRoot = new UiElement();

        // Create a controller for the Android platform
        UiController* androidController = new UiController();
        androidController->SetName("AndroidController");
        androidController->SetParent(kControllerRoot);

        // Add the controller to the root element
        kControllerRoot->AddChild(androidController);
    }
}
