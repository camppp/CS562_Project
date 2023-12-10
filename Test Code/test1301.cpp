void ParticleEmitter::updateParticles(float dt)
{
    for (auto it = particles.begin(); it != particles.end();)
    {
        it->x += it->vx * dt;  // Update position based on velocity
        it->y += it->vy * dt;
        it->lifetime -= dt;  // Reduce remaining lifetime

        if (it->lifetime <= 0.0f)
        {
            it = particles.erase(it);  // Remove particle if lifetime has expired
        }
        else
        {
            ++it;
        }
    }
}
