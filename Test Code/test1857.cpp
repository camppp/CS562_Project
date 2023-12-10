void scale(QPolygonF polygon, QSize targetSize) {
    // Calculate the scale factor
    qreal scaleFactor = targetSize.width() / polygon.boundingRect().width();

    // Scale the polygon's points
    for (int i = 0; i < polygon.size(); i++) {
        polygon[i] = polygon[i] * scaleFactor;
    }
}
