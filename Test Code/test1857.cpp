QPolygonF EFXPreviewArea::scale(const QPolygonF& poly, const QSize& target)
{
    QPolygonF scaled;
    for (int i = 0; i < poly.size(); i++)
    {
        QPointF pt = poly.at(i);
        pt.setX((int) SCALE(qreal(pt.x()), qreal(0), qreal(255), qreal(0), qreal(target.width())));
        pt.setY((int) SCALE(qreal(pt.y()), qreal(0), qreal(255), qreal(0), qreal(target.height())));
        scaled << pt;
    }
    return scaled;
}
