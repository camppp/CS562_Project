#include <iostream>
#include <thread>
#include "SharedRenderContext.h" // Include the header file for the SharedRenderContext class

int main()
{
    sp::video::SharedRenderContext renderContext;

    // Create multiple threads to simulate resource creation and destruction
    std::thread thread1([&renderContext]() {
        renderContext.createResource("Texture1");
        renderContext.destroyResource("Texture1");
    });

    std::thread thread2([&renderContext]() {
        renderContext.createResource("Buffer1");
        renderContext.destroyResource("Buffer1");
    });

    // Wait for the threads to finish
    thread1.join();
    thread2.join();

    return 0;
}
