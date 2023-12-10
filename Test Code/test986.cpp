#include <stdio.h>
#include <stdlib.h>

#define CUT_DIR_X 0
#define CUT_DIR_Y 1

typedef struct {
    int start;
    int end;
} IndexRange;

IndexRange divide_grid(int nx, int ny, int myid, int numprocs, int cut_dir) {
    int start, end;
    if (cut_dir == CUT_DIR_X) {
        start = (nx * myid) / numprocs;
        end = (nx * (myid + 1)) / numprocs;
    } else {
        start = (ny * myid) / numprocs;
        end = (ny * (myid + 1)) / numprocs;
    }
    return (IndexRange){start, end};
}

int main() {
    int nx = 10; // Total size of the grid in the x-direction
    int ny = 8;  // Total size of the grid in the y-direction
    int numprocs = 4;  // Total number of processes
    int myid = 2;  // Process ID
    int cut_dir = CUT_DIR_X;  // Direction of the cut (CUT_DIR_X or CUT_DIR_Y)

    IndexRange range = divide_grid(nx, ny, myid, numprocs, cut_dir);
    printf("Process %d handles indices [%d, %d]\n", myid, range.start, range.end);

    return 0;
}
