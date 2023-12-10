java
public List<String> depthFirstSearch(Node construct, String startNodeIdentifier) {
    List<String> visitedNodes = new ArrayList<>();
    Set<String> visitedSet = new HashSet<>();
    depthFirstSearchHelper(construct, startNodeIdentifier, visitedNodes, visitedSet);
    return visitedNodes;
}

private void depthFirstSearchHelper(Node node, String identifier, List<String> visitedNodes, Set<String> visitedSet) {
    if (node == null || visitedSet.contains(identifier)) {
        return;
    }
    visitedNodes.add(identifier);
    visitedSet.add(identifier);
    for (Node child : node.children) {
        depthFirstSearchHelper(child, child.identifier, visitedNodes, visitedSet);
    }
}
