#include <iostream>

struct LNode {
    int data;
    struct LNode* next;
};

int* solve(int N, int M, int K) {
    int* a = new int[N - K];
    int j = 0;
    LNode* L = new LNode;
    LNode* r = L;
    for (int i = 1; i <= N; i++) {
        LNode* p = new LNode;
        p->data = i;
        p->next = NULL;
        r->next = p;
        r = r->next;
    }

    LNode* current = L->next;
    LNode* prev = L;
    int count = 0;
    while (current != NULL) {
        count++;
        if (count >= M && count < M + K) {
            LNode* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        } else {
            a[j++] = current->data;
            current = current->next;
        }
    }

    return a;
}

int main() {
    int N = 5, M = 2, K = 2;
    int* result = solve(N, M, K);
    for (int i = 0; i < N - K; i++) {
        std::cout << result[i] << " ";
    }
    delete[] result;
    return 0;
}
