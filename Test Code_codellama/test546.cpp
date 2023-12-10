#include <queue>

void levelOrderTraversal(const data_structures::BinarySearchTree<int>& tree, std::function<void(int&)> print) {
    std::queue<data_structures::BinarySearchTree<int>::Node*> queue;
    queue.push(tree.getRoot());

    while (!queue.empty()) {
        data_structures::BinarySearchTree<int>::Node* node = queue.front();
        queue.pop();

        print(node->key);

        if (node->left != nullptr) {
            queue.push(node->left);
        }

        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }
}
