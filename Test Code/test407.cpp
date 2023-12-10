#include <unordered_set>

bool hasCircularDependency(SharedPtr<CircularDependencyObject> obj) {
    std::unordered_set<SharedPtr<CircularDependencyObject>> visited;

    while (obj != nullptr) {
        if (visited.count(obj) > 0) {
            return true;  // Circular dependency detected
        }
        visited.insert(obj);
        obj = obj->getOther();
    }

    return false;  // No circular dependency found
}
