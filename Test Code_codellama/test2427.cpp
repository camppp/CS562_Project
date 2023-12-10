int calculateSum(int b[][]) {
    int sum = 0;
    for (int i = 0; i < b.nblocks(); i++) {
        for (int j = 0; j < b.mblocks(); j++) {
            sum += b.i(i, j);
        }
    }
    return sum;
}
