QStyle* createStyle() {
    QString theme = QApplication::theme();
    if (theme == "dark") {
        return QStyleFactory::create("Fusion");
    } else {
        return QStyleFactory::create("Windows");
    }
}
