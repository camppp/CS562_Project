void insertIntoLinkedList(Line **ppHead, char *pszCommentStart, size_t uiStrLen) {
    Line *newLine = (Line *)malloc(sizeof(Line));
    newLine->pszComment = (char *)malloc((uiStrLen + 1) * sizeof(char)); // Allocate memory for the comment string
    f_memcpy(newLine->pszComment, pszCommentStart, uiStrLen); // Copy the comment string
    newLine->pszComment[uiStrLen] = '\0'; // Null-terminate the comment string

    newLine->pNext = *ppHead; // Set the next pointer of the new struct to the current head of the linked list
    *ppHead = newLine; // Update the head of the linked list to point to the new struct
}
