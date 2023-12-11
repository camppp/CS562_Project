__global__ void copy_arrays(int n, T *xa, T *ya, int shiftx, int shifty, int stridex, int stridey, int incx, int incy) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < n) {
        T x = load_ptr_batch(xa, tid, shiftx, stridex, incx);
        store_ptr_batch(ya, tid, shifty, stridey, incy, x);
    }
}
