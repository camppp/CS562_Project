bool AUIComboWidget::OnMouseLBtnUp(MAUIMouseEvent::EventFlag eventFlag)
{
    // Check if the event is a left mouse button up event
    if (eventFlag == MAUIMouseEvent::LeftButtonUp)
    {
        // If the left mouse button is released over the combo box,
        // open the drop-down list and select the current item
        if (IsMouseOverCombo())
        {
            OpenDropDownList();
            SelectCurrentItem();
            return true;
        }
    }

    // If the event is not a left mouse button up event or
    // the mouse is not over the combo box, return false
    return false;
}
