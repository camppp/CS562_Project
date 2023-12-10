void printPostOrder(Node* node) {
    if (node != nullptr) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->key << " ";
    }
}
