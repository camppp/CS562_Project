void MainWindow::writeSettings() {
    QSettings settings("organization", "application"); // Replace "organization" and "application" with appropriate values

    settings.beginGroup("settings");
    settings.setValue("darkModeEnabled", ui->checkBox_settingsDarkMode->isChecked());
    settings.setValue("useOpenGL", ui->checkBox_settingsOpenGL->isChecked());
    settings.endGroup();
}

void MainWindow::readSettings() {
    QSettings settings("organization", "application"); // Replace "organization" and "application" with appropriate values

    settings.beginGroup("settings");
    ui->checkBox_settingsDarkMode->setChecked(settings.value("darkModeEnabled").toBool());
    ui->checkBox_settingsOpenGL->setChecked(settings.value("useOpenGL").toBool());
    settings.endGroup();
}
