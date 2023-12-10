void UIControl::addInlineVisual(UIElement* element, UIInlinePlacement layout)
{
    // Handle the inline layout
    if (layout == UIInlinePlacement::Inline)
    {
        // Place the element at the first position in the grid
        element->setPosition(pts[0]);
    }
    // Handle the stacked layout
    else if (layout == UIInlinePlacement::Stacked)
    {
        // Place the element at the first position in the grid
        element->setPosition(pts[0]);
        // Place the element at the second position in the grid
        element->setPosition(pts[1]);
        // Place the element at the third position in the grid
        element->setPosition(pts[2]);
    }
    // Handle the custom layout
    else if (layout == UIInlinePlacement::Custom)
    {
        // Place the element at the first position in the grid
        element->setPosition(pts[0]);
        // Place the element at the second position in the grid
        element->setPosition(pts[1]);
        // Place the element at the third position in the grid
        element->setPosition(pts[2]);
    }
    // Handle the default layout
    else
    {
        // Place the element at the first position in the grid
        element->setPosition(pts[0]);
    }
}
