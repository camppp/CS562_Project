// Define a function to detect and resolve collisions in the hierarchical data structure
void DetectAndResolveCollisions(CoreGenNode *HW, std::unordered_map<CoreGenNode*, unsigned> &IdxMap) {
  // Iterate through the child nodes of the parent node
  for (unsigned i = 0; i < HW->GetNumChild(); i++) {
    CoreGenNode *CNode = HW->GetChild(i);

    // Check if the child node is of type CGComm and if it has a collision
    if (CNode->GetType() == CGComm && IdxMap.find(CNode) == IdxMap.end()) {
      // If there is a collision, resolve it by updating the index
      // Here, we can update the index of the node CNode based on the collision resolution strategy
      // For example, we can assign a new unique index to resolve the collision
      unsigned newIndex = GenerateUniqueIndex(); // Function to generate a unique index
      IdxMap[CNode] = newIndex; // Update the index in the map
      // Perform any other necessary actions to resolve the collision
    }
  }
}

// Example of a function to generate a unique index
unsigned GenerateUniqueIndex() {
  static unsigned indexCounter = 0;
  return indexCounter++; // Increment and return the index counter
}
