void setTextColor(bool isPressedDown, Color highlightColor, Color borderColor) {
    if (isPressedDown) {
        onLbl.setTextColor(highlightColor);
        offLbl.setTextColor(borderColor);
    } else {
        onLbl.setTextColor(borderColor);
        offLbl.setTextColor(highlightColor);
    }
}
