public Node collapseParentNodes(Node root) {
    if (root instanceof ParentNode) {
        ParentNode parentNode = (ParentNode) root;
        List<Node> children = parentNode.children();
        for (int i = 0; i < children.size(); i++) {
            Node child = children.get(i);
            if (child instanceof ParentNode) {
                ParentNode childParentNode = (ParentNode) child;
                if (childParentNode.getClass().equals(parentNode.getClass())) {
                    children.remove(i);
                    children.addAll(childParentNode.children());
                    i--;
                }
            }
        }
        parentNode.children().clear();
        parentNode.children().addAll(children);
    }
    for (Node child : ((ParentNode) root).children()) {
        collapseParentNodes(child);
    }
    return root;
}