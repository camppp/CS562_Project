void heapifyUp(int index) {
    while (index > 0 && heap[index].second < heap[index / 2].second) {
        swap(heap[index], heap[index / 2]);
        index /= 2;
    }
}
