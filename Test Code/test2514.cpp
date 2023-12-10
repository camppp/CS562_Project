void drawShape(int modeIndex, int startX, int startY, int endX, int endY, QPainter& p) {
    if (modeIndex == shapeRectangle) {
        p.drawRect(startX, startY, endX - startX, endY - startY);
    }
}
