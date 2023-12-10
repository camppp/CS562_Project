void LControlPage::setControlPage(const QString &a_rHtmlPath)
{
    // Load the HTML file into the web view
    ui->webView->setHtml(readHtmlFile(a_rHtmlPath));

    // Display the web view
    ui->webView->show();
}

QString LControlPage::readHtmlFile(const QString &filePath)
{
    // Read the contents of the HTML file
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        return in.readAll();
    } else {
        // Handle file read error
        qDebug() << "Error: Unable to open file " << filePath;
        return QString(); // Return empty string in case of error
    }
}
