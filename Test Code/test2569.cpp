void RenderFullScreen::setPlaceholder(RenderBlock* placeholder)
{
    RenderObject* child;
    while ((child = firstChild())) {
        child->remove();  // Remove the child from its current position in the rendering hierarchy
        holder->parent()->addChild(child, holder);  // Add the removed child to the parent of the 'holder' element
    }
    remove();  // Remove the 'RenderFullScreen' object itself from the rendering hierarchy
    document()->setFullScreenRenderer(0);  // Set the full-screen renderer of the document to null
}
