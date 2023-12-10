bool ofxSoundObject::checkForInfiniteLoops() {
    // Create a set to keep track of the objects in the chain
    std::set<ofxSoundObject*> visited;

    // Start at this object and traverse the chain
    ofxSoundObject* current = this;
    while (current != nullptr) {
        // If the current object is already in the set, it means we have a loop
        if (visited.find(current) != visited.end()) {
            ofLogError("Infinite loop detected in audio processing chain");
            disconnect();
            return false;
        }

        // Add the current object to the set
        visited.insert(current);

        // If the current object has an input object, traverse the chain recursively
        if (current->input != nullptr) {
            current = current->input;
        } else {
            // If the current object has no input object, we have reached the end of the chain
            break;
        }
    }

    // If we have reached the end of the chain without finding an infinite loop, return true
    return true;
}
