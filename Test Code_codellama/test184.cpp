#include <iostream>
#include <string>

class BodyNode {
public:
    // ...
    std::string body_type() {
        if (cpSpaceExists(cpSpace) && cpSpaceHasUserData(cpSpace)) {
            return SpaceNode::getType(cpSpace);
        } else {
            return "Unknown";
        }
    }
};
