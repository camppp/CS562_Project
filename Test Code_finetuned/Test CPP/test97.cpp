bool Engine::CreateReality(const Layout& layout) {
    if (layout.lreality == nullptr || layout.lrenderer == nullptr) {
        // Handle error: lreality or lrenderer is null
        return false;
    }

    // Initialize the virtual reality environment
    layout.lreality->Initialize(layout.lrenderer);

    return true;
}