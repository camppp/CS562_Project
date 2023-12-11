void updateParticlePositionAndMaturity(Particle* p, int px, int py, int width, int height) {
    // Calculate the position of the particle in the grid
    int pos = xy2pos(px, py);

    // Update the particle's position
    p->pos = pos;

    // Check if the particle is mature
    if (!p->mature) {
        // Update the particle's maturity status
        p->mature = true;
    }
}
