#include <Altseed.h>

int main()
{
    // Initialize the graphics module
    Altseed::Initialize();

    // Create a window for the application
    Altseed::Window window;
    window.Create();

    // Terminate the graphics module
    Altseed::Terminate();

    return 0;
}
