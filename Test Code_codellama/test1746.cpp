void MainWindow::FileSelected(const QString &filePath) {
    // Process the selected file's path
    QFileInfo fileInfo(filePath);
    if (fileInfo.isFile()) {
        // File is selected, do something with it
        QMessageBox::information(this, "File Selected", "The file " + fileInfo.fileName() + " has been selected.");
    } else {
        // File is not selected, do something else
        QMessageBox::warning(this, "File Not Selected", "The file " + fileInfo.fileName() + " was not selected.");
    }
}
