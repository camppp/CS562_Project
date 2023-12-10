void print(struct Queue *q) {
    if (q->front == -1) // No elements 
    {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
