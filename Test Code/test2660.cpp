#include <stdio.h>
#include <stdbool.h>

#define MAX_CITIES 100  // maximum number of cities

bool in_queue[MAX_CITIES];  // boolean array to track if a city is in the queue
int adjacency_matrix[MAX_CITIES][MAX_CITIES];  // adjacency matrix representing the network of cities
int n;  // number of cities

void bfs(int start_city, int city_concern) {
    // Initialize a queue for BFS traversal
    int queue[MAX_CITIES];
    int front = 0, rear = 0;
    queue[rear++] = start_city;
    in_queue[start_city] = true;

    while (front < rear) {
        int current_city = queue[front++];
        for (int city = 1; city <= n; city++) {
            if (city != city_concern && adjacency_matrix[current_city][city] && !in_queue[city]) {
                queue[rear++] = city;
                in_queue[city] = true;
            }
        }
    }
}

int main() {
    int city_concern, component = 0;
    scanf("%d", &city_concern);
    for (int city = 1; city <= n; city++) {
        if (city != city_concern && !in_queue[city]) {
            bfs(city, city_concern);
            component++;
        }
    }
    printf("%d\n", component == 0 ? 0 : component - 1);
    return 0;
}
