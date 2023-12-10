QString formatSizeList(const QList<QSize> &sList) {
    QString rep;
    foreach (const QSize &size, sList) {
        rep += QString("%1x%2;").arg(size.width()).arg(size.height());
    }
    return rep;
}
