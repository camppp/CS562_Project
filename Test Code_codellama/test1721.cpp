void UpdateAnimationFrame(Entity* theEntity, float elapsedTime, uint32_t totalFrames)
{
    // Get the current frame from the entity's properties
    uint32_t currentFrame = theEntity->mProperties.uCurrentFrame;

    // Calculate the new frame based on the elapsed time and total frames
    uint32_t newFrame = currentFrame + (uint32_t)(elapsedTime * totalFrames);

    // Update the entity's properties with the new frame
    theEntity->mProperties.uCurrentFrame = newFrame;
}
