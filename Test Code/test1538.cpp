void Node::parseNode(Node* node) {
    // Base case: if the current node is null, return
    if (node == nullptr) {
        return;
    }

    // Process the current node based on its type
    switch (node->type) {
        case BeginTag: {
            // Create a new child node and parse it
            Node* child = node->appendChild(name, attr);
            parseNode(child);
            break;
        }
        case EndTag:
        case Text: {
            // Continue parsing the next sibling node
            parseNode(node->nextSibling);
            break;
        }
    }
}
