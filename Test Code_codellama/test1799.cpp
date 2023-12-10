template <typename T>
static MapPtr dynamicCast(T* ptr) {
    return MapPtr(dynamic_cast<Type*>(ptr));
}
