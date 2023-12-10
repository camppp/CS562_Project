// Implementation of GetComponentContainer function
template <typename ComponentType>
ComponentContainer<ComponentType> &ECSManager::GetComponentContainer() {
    size_t componentIndex = typeid(ComponentType).hash_code();
    auto iter = containers.find(componentIndex);
    if (iter != containers.end()) {
        // Return reference to existing component container
        return static_cast<ComponentContainer<ComponentType> &>(*iter->second.get());
    } else {
        // Create a new component container and return reference to it
        containers[componentIndex] = std::make_unique<ComponentContainer<ComponentType>>(ecsEventDispatcher);
        return static_cast<ComponentContainer<ComponentType> &>(*containers[componentIndex].get());
    }
}
