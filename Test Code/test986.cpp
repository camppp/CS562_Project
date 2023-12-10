IndexRange divide_grid(int nx, int ny, int myid, int numprocs, int cut_dir) {
    IndexRange range;
    int n_layers;

    if (cut_dir == CUT_DIR_X) {
        range.start = (int) myid * ((double) nx / numprocs);
        range.end = (int) (myid + 1) * ((double) nx / numprocs) - 1;
        n_layers = nx;
    } else if (cut_dir == CUT_DIR_Y) {
        range.start = (int) myid * ((double) ny / numprocs);
        range.end = (int) (myid + 1) * ((double) ny / numprocs) - 1;
        n_layers = ny;
    }

    return range;
}
