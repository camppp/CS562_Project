#include <Altseed.h>

int main() {
    // Initialize the graphics module
    asd::Engine::Initialize(asd::ToAString("YourGameTitle").c_str(), 640, 480, asd::EngineOption());

    // Create a window for the application
    auto window = std::make_shared<asd::Window>();
    window->SetTitle(asd::ToAString("YourWindowTitle").c_str());
    asd::Engine::AddWindow(window);

    // Terminate the graphics module
    asd::Engine::Terminate();

    return 0;
}
