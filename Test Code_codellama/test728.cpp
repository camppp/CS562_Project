float CalculateTotalSigmas(const Track* track, ParticleSpecies species)
{
    // Check if custom Bethe-Bloch parameters should be used
    if (fUseCustomBethe[species]) {
        // Use custom Bethe-Bloch parameters
        return NumberOfSigmasITS(track, species) + NumberOfSigmasTPC(track, species);
    } else {
        // Use default Bethe-Bloch parameters
        return NumberOfSigmasITS(track, species) + NumberOfSigmasTPC(track, species);
    }
}
