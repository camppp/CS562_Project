public Node collapseParentNodes(Node root) {
    if (root == null) {
        return null;
    }

    // Recursively collapse the children nodes
    for (Node child : root.children()) {
        collapseParentNodes(child);
    }

    // Check if the parent node has children of the same type as the parent node
    if (root.parent() != null && root.parent().getClass().equals(root.getClass())) {
        // Collapse the parent node and add the children to the parent node's parent
        Node parent = root.parent();
        for (Node child : root.children()) {
            parent.addChild(child);
        }
        return parent;
    }

    return root;
}