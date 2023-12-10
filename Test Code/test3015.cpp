void cUnderWater::RenderUnderWater() {
    // Set rendering states for underwater scene
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Render the underwater scene
    // Assuming there are additional rendering functions for underwater scene
    // Example: renderUnderwaterScene();

    // Clear the depth buffer of the framebuffer target
    m_Depth.Clear(CORE_FRAMEBUFFER_TARGET_DEPTH);
}
