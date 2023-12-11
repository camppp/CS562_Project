int totalSize(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int size = 0;
    if (node->isFile) {
        // If the node is a file, add its size
        size += node->name.size();
    } else {
        // If the node is a directory, recursively calculate the total size of its children
        for (Node* child : node->children) {
            size += totalSize(child);
        }
    }
    return size;
}
