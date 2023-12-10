__global__ void copyArrayElements(const T* xa, T* ya, int shiftx, int shifty, int stridex, int stridey, int incx, int incy, int n) {
    ptrdiff_t tid = hipBlockIdx_x * hipBlockDim_x + hipThreadIdx_x;
    // bound
    if(tid < n)
    {
        const T* x = load_ptr_batch(xa, hipBlockIdx_y, shiftx, stridex);
        T* y = load_ptr_batch(ya, hipBlockIdx_y, shifty, stridey);

        y[tid * incy] = x[tid * incx];
    }
}
