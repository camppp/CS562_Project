int* process_packets(int** packets, int num_packets, int* packet_sizes) {
    int* sums = (int*)malloc(num_packets * sizeof(int));
    for (int i = 0; i < num_packets; i++) {
        int sum = 0;
        for (int j = 0; j < packet_sizes[i]; j++) {
            sum += packets[i][j];
        }
        sums[i] = sum;
    }
    return sums;
}