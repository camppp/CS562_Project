#include <argon/vm.h>

void argon::vm::ContextDel(Context* context) {
  // Release the memory associated with the context
  Release(context);

  // Iterate over the namespaces in the context
  for (auto& namespace_ : context->namespaces) {
    // Get the value associated with the namespace
    auto value = NamespaceGetValue(namespace_);

    // Release the memory associated with the value
    Release(value);
  }
}
