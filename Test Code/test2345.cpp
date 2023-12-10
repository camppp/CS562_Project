void distributePressureValues(const std::vector<double>& pressureValues, std::vector<std::vector<global_no_t>>& dofNosGlobalNaturalPressure, std::vector<std::vector<double>>& valuesPressure) {
    int numRanks = dofNosGlobalNaturalPressure.size();
    int valuesPerRank = pressureValues.size() / numRanks;
    
    for (int rank = 0; rank < numRanks; ++rank) {
        int startIdx = rank * valuesPerRank;
        int endIdx = (rank == numRanks - 1) ? pressureValues.size() : (rank + 1) * valuesPerRank;
        
        dofNosGlobalNaturalPressure[rank].resize(endIdx - startIdx);
        valuesPressure[rank].resize(endIdx - startIdx);
        
        for (int i = startIdx; i < endIdx; ++i) {
            dofNosGlobalNaturalPressure[rank][i - startIdx] = calculateGlobalDof(i); // Replace with actual calculation
            valuesPressure[rank][i - startIdx] = pressureValues[i];
        }
    }
}
