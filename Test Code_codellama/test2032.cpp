template <typename CtrT, typename NodeTypes>
VoidResult treeNode(const BranchNodeSO<CtrT, NodeTypes>& node, WalkCmd cmd, int32_t start, int32_t end) noexcept
{
    switch (cmd)
    {
        case WalkCmd::PreOrder:
            // Pre-order traversal
            for (int32_t i = start; i <= end; i++)
            {
                // Visit the current node
                node.visit(i);

                // Visit the left child node
                if (node.hasLeftChild())
                {
                    treeNode(node.getLeftChild(), cmd, start, end);
                }

                // Visit the right child node
                if (node.hasRightChild())
                {
                    treeNode(node.getRightChild(), cmd, start, end);
                }
            }
            break;

        case WalkCmd::InOrder:
            // In-order traversal
            if (node.hasLeftChild())
            {
                treeNode(node.getLeftChild(), cmd, start, end);
            }

            // Visit the current node
            node.visit(start);

            if (node.hasRightChild())
            {
                treeNode(node.getRightChild(), cmd, start, end);
            }
            break;

        case WalkCmd::PostOrder:
            // Post-order traversal
            if (node.hasLeftChild())
            {
                treeNode(node.getLeftChild(), cmd, start, end);
            }

            if (node.hasRightChild())
            {
                treeNode(node.getRightChild(), cmd, start, end);
            }

            // Visit the current node
            node.visit(start);
            break;

        default:
            // Unknown command
            break;
    }
}
