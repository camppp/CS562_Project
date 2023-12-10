void detectAndResolveCollisions(CoreGenNode* parent) {
    // Iterate through the child nodes of the parent node
    for (auto child : parent->getChildren()) {
        // Check if the child node is of type CGComm
        if (child->getType() == CGComm) {
            // Check if the child node has a collision with another node
            if (IdxMap.find(child->getIndex()) != IdxMap.end()) {
                // Resolve the collision by updating the indices of the nodes
                int newIndex = IdxMap[child->getIndex()];
                child->setIndex(newIndex);
                IdxMap[newIndex] = child;
            }
        }
    }
}
