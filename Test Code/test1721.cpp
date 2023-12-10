void UpdateAnimationFrame(Entity* theEntity, float elapsedTime, uint32_t totalFrames) {
    sf::Clock* animationClock = theEntity->mProperties.Get<sf::Clock>("AnimationClock");
    uint32_t currentFrame = theEntity->mProperties.GetUint32("uCurrentFrame");

    // Update the animation frame based on the elapsed time
    float frameDuration = 1.0f; // Assuming each frame has a duration of 1 second
    float timeSinceLastFrame = animationClock->restart().asSeconds();
    currentFrame += static_cast<uint32_t>(timeSinceLastFrame / frameDuration);

    // Ensure the current frame stays within the valid range
    currentFrame %= totalFrames;

    // Update the "uCurrentFrame" property in the mProperties container
    theEntity->mProperties.SetUint32("uCurrentFrame", currentFrame);
}
