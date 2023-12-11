#include <string>

// Define the BinderCallback type
using BinderCallback = void (*)(const std::string& interface_name, mojo::ScopedMessagePipeHandle pipe);

// Define the BindInterface function
void BindInterface(mojo::PendingReceiver<Interface> receiver, BinderCallback binder_callback) {
  // Retrieve the name of the interface from the receiver
  std::string interface_name = Interface::Name_;

  // Invoke the binder callback with the interface name and the passed pipe
  binder_callback(interface_name, receiver.PassPipe());
}
