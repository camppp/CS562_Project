c
int* solve(int N, int M, int K) {
    // Create a linked list with N nodes
    struct LNode* head = NULL;
    struct LNode* current = head;
    for (int i = 0; i < N; i++) {
        current->data = i;
        current->next = new LNode();
        current = current->next;
    }

    // Delete K nodes starting from position M
    current = head;
    for (int i = 0; i < M - 1; i++) {
        current = current->next;
    }
    for (int i = 0; i < K; i++) {
        struct LNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Return an array containing the data of the remaining nodes
    int* result = new int[N - K];
    current = head;
    for (int i = 0; i < N - K; i++) {
        result[i] = current->data;
        current = current->next;
    }
    return result;
}
