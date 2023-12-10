int calculateTotalRval(Node** node, int to, Range* range_p, int srcStride) {
    int rval = 0;
    NArgs nargs;

    for (int i = (*node)->idxf_; i <= to; i++) {
        SlicedPathIterator it(*node, range_p);
        rval += dispatchWrite(&it, &nargs);

        nargs.off_ += getStride();
        nargs.src_ += srcStride;
    }

    return rval;
}
