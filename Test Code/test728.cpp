float CalculateTotalSigmas(const Track* track, ParticleSpecies species) {
    const float nSigmaITS = fPID->NumberOfSigmasITS(track, species);
    float nSigmaTPC = fPID->NumberOfSigmasTPC(track, species);
    if (fUseCustomBethe[species]) {
        const float betaGamma = track->GetTPCmomentum() / AliPID::ParticleMass(species);
        const float* pars = fCustomBethe[species];
        // Calculate nSigmaTPC using custom Bethe-Bloch parameters
        // nSigmaTPC = ... (calculation using custom parameters)
    }
    return nSigmaITS + nSigmaTPC;
}
