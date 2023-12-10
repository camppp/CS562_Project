python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def minDiffInBST(root):
    def inorder_traversal(node, result):
        if node:
            inorder_traversal(node.left, result)
            result.append(node.val)
            inorder_traversal(node.right, result)

    values = []
    inorder_traversal(root, values)
    min_diff = float('inf')
    for i in range(1, len(values)):
        min_diff = min(min_diff, values[i] - values[i-1])
    return min_diff
