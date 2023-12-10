template <typename ComponentType>
ComponentContainer<ComponentType> &ECSManager::GetComponentContainer() {
    size_t componentIndex = typeid(ComponentType).hash_code();
    auto iter = containers.find(componentIndex);
    if (iter != containers.end()) {
        return *static_cast<ComponentContainer<ComponentType>*>(iter->second.get());
    } else {
        containers.emplace(componentIndex, std::make_unique<ComponentContainer<ComponentType>>(ecsEventDispatcher));
        return *static_cast<ComponentContainer<ComponentType>*>(containers.at(componentIndex).get());
    }
}
