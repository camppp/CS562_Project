void populateRimap(Long[] Sj, Double[] Sx, int i, int fn, cpuElement[] cpuS) {
    // Initialize the Rimap data structure
    Rimap rimap = new Rimap();

    // Loop through the cpuS array
    for (int p = 0; p < cpuS.length; p++) {
        // Calculate the findex for the current cpuElement
        int findex = calculateFindex(i, fn, cpuS[p].findex);

        // Add the current cpuElement to the Rimap data structure
        rimap.add(findex, cpuS[p].value);
    }

    // Return the populated Rimap data structure
    return rimap;
}

int calculateFindex(int i, int fn, int findex) {
    // Calculate the findex for the current cpuElement
    return i + fn + findex;
}
