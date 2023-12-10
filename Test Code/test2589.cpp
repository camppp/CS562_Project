bool ini_class::file_exists(const QString &_file_path) {
    QFileInfo fi(_file_path);
    return fi.exists();
}
