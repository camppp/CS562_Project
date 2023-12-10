bool validateRootCertificateInput(const QString& filename)
{
    if (filename.isEmpty()) {
        QMessageBox::warning(nullptr, "Error", "ルート証明書の指定は必須です");
        return false;
    }
    return true;
}
