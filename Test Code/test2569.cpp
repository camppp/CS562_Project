void RenderFullScreen::setPlaceholder(RenderBlock* placeholder)
{
    // Iterate through all child elements of the RenderFullScreen object
    RenderObject* child;
    while ((child = firstChild())) {
        // Remove the child element from its current position in the rendering hierarchy
        child->remove();
        // Add the removed child element to the parent of the holder element in the rendering hierarchy
        holder->parent()->addChild(child, holder);
    }
    // Remove the RenderFullScreen object itself from the rendering hierarchy
    remove();
    // Set the full-screen renderer of the document to null
    document()->setFullScreenRenderer(nullptr);
}
