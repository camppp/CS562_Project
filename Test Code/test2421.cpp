void Button::GUIUpdate(float deltaTime)
{
    if (TextLabel_ != nullptr) {
        TextLabel_->SetLabel(Label_);  // Set the label of the TextLabel to the value of Label_
        TextLabel_->baseColor = textColor;  // Update the base color of the TextLabel
    }
}
