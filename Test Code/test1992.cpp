void initializeArrays(Atom* atom, Neighbor* nq, Memory* memory) {
    int ntypes = atom->ntypes;
    int* iskip = new int[ntypes+1];
    int** ijskip = new int*[ntypes+1];
    for (int i = 1; i <= ntypes; i++) {
        iskip[i] = nq->iskip[i];
        ijskip[i] = new int[ntypes+1];
    }
    for (int i = 1; i <= ntypes; i++) {
        for (int j = 1; j <= ntypes; j++) {
            ijskip[i][j] = nq->ijskip[i][j];
        }
    }
    memory->create(ijskip, ntypes+1, ntypes+1, "neigh_list:ijskip");
}
