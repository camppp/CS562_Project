void ParticleEmitter::updateParticles(float dt)
{
    for (int i = 0; i < particles.size(); i++)
    {
        Particle& particle = particles[i];
        particle.x += particle.vx * dt;
        particle.y += particle.vy * dt;
        particle.lifetime -= dt;
        if (particle.lifetime <= 0)
        {
            particles.erase(particles.begin() + i);
            i--;
        }
    }
}
