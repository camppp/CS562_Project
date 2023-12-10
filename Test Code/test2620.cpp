namespace opencl
{
    template<typename T>
    void transpose_inplace(Array<T> &in, const bool conjugate)
    {
        dim4 iDims = in.dims();

        if(conjugate) {
            if(iDims[0] % kernel::TILE_DIM == 0 && iDims[1] % kernel::TILE_DIM == 0)
                kernel::transpose_inplace<T, true, true>(in);
            else
                kernel::transpose_inplace<T, true, false>(in);
        } else {
            if(iDims[0] % kernel::TILE_DIM == 0 && iDims[1] % kernel::TILE_DIM == 0)
                kernel::transpose_inplace<T, false, true>(in);
            else
                kernel::transpose_inplace<T, false, false>(in);
        }
    }
}
