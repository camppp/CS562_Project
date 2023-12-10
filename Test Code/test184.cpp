#include <chipmunk/chipmunk.h> // Include the appropriate header for cpSpace and cpSpaceGetUserData

enum class BodyNodeType {
    Unknown,
    // Add other body node types as needed
    // Example: Circle,
    //          Rectangle,
    //          Polygon,
};

class SpaceNode {
    // Define the SpaceNode class as needed
    // Example: Add properties and methods relevant to SpaceNode
};

class BodyNode {
public:
    // Other member variables and methods of BodyNode

    BodyNodeType body_type() {
        if (cp_space) {
            SpaceNode* spaceNode = static_cast<SpaceNode*>(cpSpaceGetUserData(cp_space));
            if (spaceNode) {
                // Assuming SpaceNode has a method to return its type
                return spaceNode->getNodeType();
            }
        }
        return BodyNodeType::Unknown; // Default value for unknown body type
    }

private:
    cpSpace* cp_space; // Assuming cp_space is a member variable representing the associated cpSpace
};
