int KthSmallestElement(Node *root, int &K)
{
    if (root == NULL)
        return -1;

    // Stack to simulate the recursive in-order traversal
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        // Decrement K for each visited node
        K--;
        if (K == 0)
            return curr->data;

        curr = curr->right;
    }

    return -1; // K is out of range
}
