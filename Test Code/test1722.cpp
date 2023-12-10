#include <iostream>

int main() {
    EventListener* listener = new EventListener();

    // Register events and names
    listener->registerEvent("onComponentBegin");
    listener->registerName("VCARD");
    listener->registerEvent("onVersion");
    listener->registerEvent("onProperty");

    // Create a sample Property object
    Property* oldStyleProp = new Property();

    // Register the sample Property
    listener->registerProperty(oldStyleProp);

    // Handle the events and verify their order
    try {
        listener->handleEvent("onComponentBegin");
        std::cout << "Event 'onComponentBegin' handled successfully" << std::endl;

        listener->handleEvent("onVersion");
        std::cout << "Event 'onVersion' handled successfully" << std::endl;

        listener->handleEvent("onProperty");
        std::cout << "Event 'onProperty' handled successfully" << std::endl;

        // Attempting to handle more events than registered
        listener->handleEvent("unexpectedEvent");
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
