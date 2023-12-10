QString formatSizeList(const QList<QSize> &sList) {
    QString rep;
    foreach(const QSize &s, sList) {
        rep += QString::number(s.width()) + "x" + QString::number(s.height()) + ";";
    }
    return rep;
}
