void HdRprApiFramebuffer::AttachAs(lava::Aov aov) {
    if (m_aov != kAovNone || aov == kAovNone) {
        LAVA_ERROR_CHECK(m_context->SetAOV(m_aov, nullptr), "Failed to detach aov framebuffer");
    }

    if (aov != kAovNone) {
        LAVA_ERROR_CHECK_THROW(m_context->SetAOV(aov, m_rprFb), "Failed to attach aov framebuffer");
    }

    m_aov = aov;
}
