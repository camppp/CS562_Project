void updateParticleVelocity(Vector3& velocity)
{
    // Add random values within the range [-2.0f, 2.0f] to the y and z components of the velocity vector
    velocity.y += random_range(-2.0f, 2.0f);
    velocity.z += random_range(-2.0f, 2.0f);

    // Multiply the updated velocity vector by Time::deltaTime and 5.0f
    velocity *= Time::deltaTime * 5.0f;
}
