#include <stdio.h>
#include <stdlib.h>

int* process_packets(int** packets, int num_packets, int* packet_sizes) {
    int *sum_array = (int*)malloc(num_packets * sizeof(int));
    
    if(sum_array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    for(int i = 0; i < num_packets; i++) {
        int sum = 0;
        for(int j = 0; j < packet_sizes[i]; j++) {
            sum += packets[i][j];
        }
        sum_array[i] = sum;
    }
    return sum_array;
}