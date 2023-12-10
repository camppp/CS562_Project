// selectNode function
Node* selectNode(Node* root, int k) {
    // If the current node is a leaf node, return it
    if (root->isLeaf()) {
        return root;
    }

    // If the current node is not a leaf node,
    // recursively call selectNode on its children
    Node* child = selectNode(root->getLeft(), k);
    if (child == nullptr) {
        child = selectNode(root->getRight(), k);
    }

    // If a child node was selected, return it
    if (child != nullptr) {
        return child;
    }

    // If no child node was selected, return the current node
    return root;
}

// chooseCentre function
Point chooseCentre(Node* node, int k) {
    // If the node is a leaf node, return its center point
    if (node->isLeaf()) {
        return node->getCenter();
    }

    // If the node is not a leaf node,
    // recursively call chooseCentre on its children
    Point leftCentre = chooseCentre(node->getLeft(), k);
    Point rightCentre = chooseCentre(node->getRight(), k);

    // If both child nodes have centres, return the average of both centres
    if (leftCentre.isValid() && rightCentre.isValid()) {
        return (leftCentre + rightCentre) / 2;
    }

    // If only one child node has a centre, return its centre
    if (leftCentre.isValid()) {
        return leftCentre;
    }
    if (rightCentre.isValid()) {
        return rightCentre;
    }

    // If no child node has a centre, return an invalid point
    return Point();
}

// split function
void split(Node* node, int k) {
    // If the node is a leaf node, return
    if (node->isLeaf()) {
        return;
    }

    // If the node is not a leaf node,
    // recursively call split on its children
    split(node->getLeft(), k);
    split(node->getRight(), k);

    // If the node has a centre, split it into two child nodes
    if (node->getCentre().isValid()) {
        // Create a new node for the left child
        Node* leftChild = new Node(node->getCentre());
        leftChild->setParent(node);
        node->setLeft(leftChild);

        // Create a new node for the right child
        Node* rightChild = new Node(node->getCentre());
        rightChild->setParent(node);
        node->setRight(rightChild);

        // Recursively call split on the new child nodes
        split(leftChild, k);
        split(rightChild, k);
    }
}
