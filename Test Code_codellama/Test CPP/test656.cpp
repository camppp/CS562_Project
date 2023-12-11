c
void updateSkew(Node** ppNode) {
    Node* pNode = *ppNode;
    switch (pNode->skew) {
        case AVL_SKEW_LEFT:
            pNode->skew = AVL_SKEW_RIGHT;
            pNode->left->skew = AVL_SKEW_NONE;
            break;
        case AVL_SKEW_RIGHT:
            pNode->skew = AVL_SKEW_NONE;
            pNode->left->skew = AVL_SKEW_LEFT;
            break;
        case AVL_SKEW_NONE:
            pNode->skew = AVL_SKEW_NONE;
            pNode->left->skew = AVL_SKEW_NONE;
            break;
    }
}
