void CalculateVisualRect(const LayoutBoxModelObject* ancestor, PhysicalRect& rect, MapCoordinatesFlags mode, VisualRectFlags visual_rect_flags) const
{
    // Handle the case where the ancestor layout box model object is null
    if (!ancestor)
    {
        rect = PhysicalRect();
        return;
    }

    // Calculate the visual rectangle based on the input parameters
    rect = ancestor->GetVisualRect(mode, visual_rect_flags);
}
