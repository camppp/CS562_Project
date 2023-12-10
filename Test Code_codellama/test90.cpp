#include <typeindex>
#include <unordered_map>
#include <stdexcept>

class Entity {
 public:
  template <typename T>
  void addComponent(Component::SharedPtr component) {
    components[typeid(T)] = component;
  }

  template <typename T>
  const T& getComponent() const {
    auto it = components.find(typeid(T));
    if (it != components.end()) {
      return static_cast<const T&>(*it->second);
    } else {
      throw std::out_of_range("Component not found");
    }
  }

 private:
  std::unordered_map<std::type_index, Component::SharedPtr> components;
};
