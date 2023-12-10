template <typename CtrT, typename NodeTypes>
VoidResult treeNode(const BranchNodeSO<CtrT, NodeTypes>& node, WalkCmd cmd, int32_t start, int32_t end) noexcept {
    if (start < 0 || end < start) {
        return VoidResult::Error("Invalid range");
    }

    if (cmd == WalkCmd::PreOrder) {
        // Perform pre-order traversal
        // Visit the current node
        // Recur on left subtree
        // Recur on right subtree
    } else if (cmd == WalkCmd::InOrder) {
        // Perform in-order traversal
        // Recur on left subtree
        // Visit the current node
        // Recur on right subtree
    } else if (cmd == WalkCmd::PostOrder) {
        // Perform post-order traversal
        // Recur on left subtree
        // Recur on right subtree
        // Visit the current node
    } else {
        return VoidResult::Error("Invalid traversal command");
    }

    // Handle different types of branch nodes
    if (std::is_same<NodeTypes, SomeNodeType>::value) {
        // Handle SomeNodeType
    } else if (std::is_same<NodeTypes, AnotherNodeType>::value) {
        // Handle AnotherNodeType
    } else {
        return VoidResult::Error("Unsupported node type");
    }

    return VoidResult::Success();
}
