c
void insertIntoLinkedList(Line **ppHead, char *pszCommentStart, size_t uiStrLen) {
    // Create a new Line struct
    Line *pNew = (Line *)malloc(sizeof(Line));
    if (pNew == NULL) {
        // Memory allocation failed
        return;
    }

    // Copy the comment string into the pszComment member of the struct
    pNew->pszComment = (char *)malloc(uiStrLen + 1);
    if (pNew->pszComment == NULL) {
        // Memory allocation failed
        free(pNew);
        return;
    }
    memcpy(pNew->pszComment, pszCommentStart, uiStrLen);
    pNew->pszComment[uiStrLen] = '\0';

    // Insert the new struct into the linked list
    pNew->pNext = *ppHead;
    *ppHead = pNew;
}
