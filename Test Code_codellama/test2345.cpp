void distributePressureValues(const std::vector<double>& pressureValues, std::vector<std::vector<global_no_t>>& dofNosGlobalNaturalPressure, std::vector<std::vector<double>>& valuesPressure) {
    // Calculate the number of pressure values per rank
    int nPressureValuesPerRank = pressureValues.size() / this->meshPartition_->nRanks();

    // Distribute the pressure values across ranks
    for (int i = 0; i < this->meshPartition_->nRanks(); i++) {
        // Calculate the starting index of the pressure values for this rank
        int startIndex = i * nPressureValuesPerRank;

        // Calculate the ending index of the pressure values for this rank
        int endIndex = (i + 1) * nPressureValuesPerRank;

        // Store the global natural degrees of freedom and pressure values for this rank
        dofNosGlobalNaturalPressure[i] = this->meshPartition_->getGlobalNaturalDofs(startIndex, endIndex);
        valuesPressure[i] = pressureValues.subvector(startIndex, endIndex);
    }
}
