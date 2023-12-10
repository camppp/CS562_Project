void Node::parseNode(Node* node) {
    // Check if the current node is a BeginTag
    if (node->type == Node::BeginTag) {
        // Create a new child node with the given name and attributes
        Node* child = node->appendChild(node->name, node->attr);
        // Recursively parse the child node
        child->parseNode(child);
    } else if (node->type == Node::EndTag || node->type == Node::Text) {
        // Continue parsing the next sibling node
        Node* next = node->nextSibling();
        if (next != nullptr) {
            next->parseNode(next);
        }
    }
}
