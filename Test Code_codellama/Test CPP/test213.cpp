public List<String> depthFirstSearch(Node construct, String startNodeIdentifier) {
    List<String> visitedNodes = new ArrayList<>();
    Stack<Node> stack = new Stack<>();
    stack.push(construct);

    while (!stack.isEmpty()) {
        Node currentNode = stack.pop();
        visitedNodes.add(currentNode.identifier);

        for (Node child : currentNode.children) {
            if (child.identifier.equals(startNodeIdentifier)) {
                stack.push(child);
            }
        }
    }

    return visitedNodes;
}
