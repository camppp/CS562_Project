DwarfNode* DwarfIterator::NextChild() {
    // If the current node is null, return null
    if (mCurrentDie == nullptr) {
        return nullptr;
    }

    // If the current node has children, return the first child
    if (mCurrentDie->HasChildren()) {
        return mCurrentDie->GetFirstChild();
    }

    // If the current node has no children, pop the parent node from the stack
    if (mParents.empty()) {
        return nullptr;
    }

    // Get the parent node from the stack
    DwarfNode* parent = mParents.top();
    mParents.pop();

    // If the parent node has children, return the next child
    if (parent->HasChildren()) {
        return parent->GetFirstChild();
    }

    // If the parent node has no children, return null
    return nullptr;
}
