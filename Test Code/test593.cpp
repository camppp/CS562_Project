int calculateSize(Node* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + calculateSize(root->left) + calculateSize(root->right);
}
