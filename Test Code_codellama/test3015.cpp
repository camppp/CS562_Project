void cUnderWater::RenderUnderWater() {
    // Set the depth function for depth buffer comparisons
    glDepthFunc(GL_LEQUAL);

    // Clear the depth buffer of the framebuffer target
    m_Depth.Clear();

    // Render the depth of the water surface
    RenderDepth();

    // Set the depth function back to the default
    glDepthFunc(GL_LESS);
}
