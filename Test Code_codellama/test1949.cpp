#include <iostream>

namespace mozart {

class UnstableNode {
public:
    UnstableNode(VM& vm) : vm_(vm) {}

    int getAbsoluteValue() {
        return std::abs(vm_.getValue());
    }

private:
    VM& vm_;
};

} // namespace mozart
