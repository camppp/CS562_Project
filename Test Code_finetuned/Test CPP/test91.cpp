from collections import deque

def nodesAtDistanceK(root, target, k):
    def dfs(node, parent=None):
        if node is None:
            return None
        if node.val == target:
            return node
        left = dfs(node.left, node)
        right = dfs(node.right, node)
        return left or right

    def bfs(node, k):
        queue = deque([(node, 0)])
        seen = {node}
        while queue:
            if queue[0][1] == k:
                return [node.val for node, _ in queue]
            node, dist = queue.popleft()
            for nei in (node.left, node.right, node.parent):
                if nei and nei not in seen:
                    seen.add(nei)
                    queue.append((nei, dist + 1))
        return []

    target_node = dfs(root)
    target_node.parent = None
    return bfs(target_node, k)