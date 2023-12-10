bool ofxSoundObject::checkForInfiniteLoops() {
    std::unordered_set<ofxSoundObject*> visited;
    ofxSoundObject* current = this;

    while (current != nullptr) {
        if (visited.count(current) > 0) {
            return false;  // Infinite loop detected
        }
        visited.insert(current);
        current = current->inputObject;
    }
    return true;  // No infinite loops found
}

void ofxSoundObject::disconnectInput(ofxSoundObject* input) {
    if (inputObject == input) {
        inputObject = nullptr;
    }
}
