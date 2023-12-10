void handleCollision(GameState* state, PowerUp* powerup, Asteroid* asteroid, Vector3 position) {
    // Add the power-up to the list of active power-ups
    state->powerups.push_back(powerup);

    // Remove the asteroid from the game state
    state->remove_asteroids.push_back(asteroid);

    // Set the power-up pointer to NULL
    powerup = NULL;

    // Trigger the explosion sound effect at the given position
    state->startRelativeSound(SOUND_ASTEROID_BOOM, position);
}
