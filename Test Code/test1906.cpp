void printPostOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->key << " ";
}
