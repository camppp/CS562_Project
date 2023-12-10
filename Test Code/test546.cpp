#include <queue>

void levelOrderTraversal(const data_structures::BinarySearchTree<int>& tree, std::function<void(int&)> print) {
	if (tree.isEmpty()) {
		return;
	}

	std::queue<data_structures::BinaryNode<int>*> levelQueue;
	levelQueue.push(tree.getRoot());

	while (!levelQueue.empty()) {
		int levelSize = levelQueue.size();
		for (int i = 0; i < levelSize; ++i) {
			data_structures::BinaryNode<int>* current = levelQueue.front();
			levelQueue.pop();
			print(current->getData());

			if (current->getLeft() != nullptr) {
				levelQueue.push(current->getLeft());
			}
			if (current->getRight() != nullptr) {
				levelQueue.push(current->getRight());
			}
		}
	}
}
