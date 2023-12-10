#include <stdio.h>

// Definition of the Node struct
typedef struct Node {
    int data;
    struct Node* pLeft;
    struct Node* pRight;
    int skew; // AVL_SKEW_NONE, AVL_SKEW_LEFT, AVL_SKEW_RIGHT
} Node;

// Function to update the skew values of a node and its left child in an AVL tree
void updateSkew(Node** ppNode) {
    if (*ppNode == NULL || (*ppNode)->pLeft == NULL) {
        return; // No node or no left child, nothing to update
    }

    switch ((*ppNode)->skew) {
        case AVL_SKEW_LEFT:
            (*ppNode)->skew = AVL_SKEW_RIGHT;
            (*ppNode)->pLeft->skew = AVL_SKEW_NONE;
            break;
        case AVL_SKEW_RIGHT:
            (*ppNode)->skew = AVL_SKEW_NONE;
            (*ppNode)->pLeft->skew = AVL_SKEW_LEFT;
            break;
        default:
            (*ppNode)->skew = AVL_SKEW_NONE;
            (*ppNode)->pLeft->skew = AVL_SKEW_NONE;
    }
}
