void MainWindow::writeSettings() {
    QSettings settings("MyApp", "Settings");
    settings.setValue("darkMode", checkBox_settingsDarkMode->isChecked());
    settings.setValue("openGL", checkBox_settingsOpenGL->isChecked());
}
