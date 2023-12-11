void initializeArrays(const Atom& atom, const NeighborList& nq, Memory& memory) {
    // Initialize an array of size ntypes+1 with values from nq->iskip
    int iskip[atom.ntypes + 1];
    for (int i = 0; i < atom.ntypes + 1; i++) {
        iskip[i] = nq.iskip[i];
    }

    // Create a 2D array of size (ntypes+1) x (ntypes+1) using memory management object memory
    int ijskip[atom.ntypes + 1][atom.ntypes + 1];
    for (int i = 0; i < atom.ntypes + 1; i++) {
        for (int j = 0; j < atom.ntypes + 1; j++) {
            ijskip[i][j] = nq.ijskip[i][j];
        }
    }

    // Populate the ijskip array with values from nq->ijskip
    for (int i = 0; i < atom.ntypes + 1; i++) {
        for (int j = 0; j < atom.ntypes + 1; j++) {
            ijskip[i][j] = nq.ijskip[i][j];
        }
    }
}
