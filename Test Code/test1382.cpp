#include <iostream>
#include <string>
#include <utility>

namespace mojo {
  template <typename T>
  class PendingReceiver {
  public:
    PendingReceiver() {}
    // Other member functions and data members can be included as per the framework's requirements.
    // ...
  };
}  // namespace mojo

// Assume the BinderCallback type is already defined as follows:
using BinderCallback = std::function<void(const std::string&, mojo::ScopedMessagePipeHandle)>;

namespace ui {
  // Assume the Interface class is already defined with a static member variable Name_.
  class Interface {
  public:
    static std::string Name_;
    // Other member functions and data members can be included as per the framework's requirements.
    // ...
  };

  std::string Interface::Name_ = "ExampleInterface";

  // Implementation of the BindInterface function
  template <typename Interface>
  void BindInterface(mojo::PendingReceiver<Interface> receiver,
                     const BinderCallback& binder_callback) {
    binder_callback(Interface::Name_, receiver.PassPipe());
  }

  // Example usage
  void ExampleBinderCallback(const std::string& interface_name, mojo::ScopedMessagePipeHandle pipe) {
    std::cout << "Binding interface: " << interface_name << std::endl;
    // Perform further processing with the interface and pipe
  }

  int main() {
    mojo::PendingReceiver<Interface> receiver;
    BindInterface(receiver, ExampleBinderCallback);
    return 0;
  }
}  // namespace ui
