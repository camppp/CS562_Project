bool normalize_alignment(Alignment& al, const string& read_seq, const string& ref_seq) {
    // Check if the alignment is valid
    if (!al.is_valid()) {
        return false;
    }

    // Check if the read sequence and reference sequence are the same length
    if (read_seq.size() != ref_seq.size()) {
        return false;
    }

    // Initialize the alignment object
    al.initialize(read_seq, ref_seq);

    // Iterate over the alignment object and check for any discrepancies
    for (int i = 0; i < al.size(); i++) {
        // Check if the read and reference sequences have a mismatch
        if (al[i].read_base != al[i].ref_base) {
            // Adjust the alignment object to reflect the mismatch
            al[i].read_base = al[i].ref_base;
        }

        // Check if the read sequence has a gap
        if (al[i].read_base == '-') {
            // Adjust the alignment object to reflect the gap
            al[i].read_base = al[i].ref_base;
        }

        // Check if the reference sequence has a gap
        if (al[i].ref_base == '-') {
            // Adjust the alignment object to reflect the gap
            al[i].ref_base = al[i].read_base;
        }
    }

    // Return true if the normalization was successful
    return true;
}
