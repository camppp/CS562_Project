void HdRprApiFramebuffer::AttachAs(lava::Aov aov) {
    // Detach the current Aov if it is not "kAovNone" and the new Aov is "kAovNone"
    if (m_aov != kAovNone && aov == kAovNone) {
        m_context->SetAOV(m_rprFb, m_aov);
        m_aov = kAovNone;
    }

    // Attach the new Aov if it is not "kAovNone"
    if (aov != kAovNone) {
        m_context->SetAOV(m_rprFb, aov);
        m_aov = aov;
    }
}
