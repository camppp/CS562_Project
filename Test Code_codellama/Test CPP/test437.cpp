bool Delete(int key) {
    // Find the node to delete
    Node* node = Find(key);
    if (node == nullptr) {
        // Key does not exist in the index
        return false;
    }

    // Delete the node
    DeleteNode(node);

    // Update the index
    UpdateIndex();

    return true;
}
