#include <iostream>
#include <typeinfo>

class Map {
    // Implementation of the Map class
};

class Type {
    // Implementation of the Type class
};

class MapPtr {
    Type* typePtr;

public:
    MapPtr(Type* ptr) : typePtr(ptr) {}

    template <typename T>
    static MapPtr dynamicCast(T* ptr) {
        if (typeid(*ptr) == typeid(Type)) {
            return MapPtr(static_cast<Type*>(ptr));
        } else {
            std::cerr << "Dynamic cast failed!" << std::endl;
            return MapPtr(nullptr);
        }
    }
};

int main() {
    Map* pPtr = new Map();
    Type* typePtr = new Type();
    MapPtr mPtr = MapPtr::dynamicCast(typePtr);

    // Your implementation should correctly perform the dynamic casting
    // and store the result in mPtr
    return 0;
}
