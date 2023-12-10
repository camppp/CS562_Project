void LControlPage::setControlPage(const QString &a_rHtmlPath)
{
    ui->webView->load(QUrl(a_rHtmlPath));
    ui->webView->show();
    ui->webView->page()->mainFrame()->evaluateJavaScript("document.body.style.backgroundColor = 'white';");
}
