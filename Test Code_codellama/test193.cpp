void deleteNode(Node* root, int key) {
    if (root == NULL) {
        return;
    }
    if (root->data == key) {
        // Node to be deleted has no children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return;
        }
        // Node to be deleted has one child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            root = temp;
            return;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            root = temp;
            return;
        }
        // Node to be deleted has two children
        Node* successor = findSuccessor(root->right);
        root->data = successor->data;
        deleteNode(root->right, successor->data);
        return;
    }
    if (root->data > key) {
        deleteNode(root->left, key);
    } else {
        deleteNode(root->right, key);
    }
}
