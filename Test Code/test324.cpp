QString indentText(const QString& text, int numSpaces) {
    QStringList lines = text.split("\n");
    for (int i = 0; i < lines.size(); i++) {
        lines[i] = QString(numSpaces, ' ') + lines[i];
    }
    return lines.join("\n");
}
