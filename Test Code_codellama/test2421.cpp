void Button::GUIUpdate(float dt)
{
    // Update the label of the TextLabel associated with the button
    TextLabel_->SetLabel(Label_);

    // Update the base color of the TextLabel
    TextLabel_->SetBaseColor(textColor);
}
