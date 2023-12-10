#include <functional>
#include <iostream>
#include <vector>

class Callback {
public:
    void AsStdFunction() {
        // Implementation not shown
    }
};

class Child {
private:
    std::vector<std::function<void()>> drainCloseCallbacks;

public:
    auto addOnDrainCloseCb(const std::function<void()>& callback) {
        drainCloseCallbacks.push_back(callback);
        return this;
    }

    void drainAndClose() {
        // Perform draining operations
        for (const auto& callback : drainCloseCallbacks) {
            callback();
        }
        std::cout << "Child drained and closed" << std::endl;
    }
};

class Parent {
private:
    Child* child;
    std::function<void()> parentDrainCallback;

public:
    Parent(Child* c) : child(c) {}

    void startDrainSequence(const std::function<void()>& callback) {
        parentDrainCallback = callback;
        child->drainAndClose();
        parentDrainCallback();
    }
};

int main() {
    Child c;
    Parent p(&c);

    auto cb = Callback();
    auto handle_c = c.addOnDrainCloseCb(cb.AsStdFunction());

    // Drain the child, then the parent
    p.startDrainSequence([] {
        std::cout << "Parent drained" << std::endl;
    });

    return 0;
}
