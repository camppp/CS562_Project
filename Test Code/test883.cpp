void addBibliographyEntry(QWidget *ui, const QString &bibliographyEntry) {
    // Add the bibliography entry to the data structure
    bibliography.push_back(bibliographyEntry);

    // Update the bibliography in the user interface
    ui->bibliographyBLineEdit->clear();
    for (const QString &entry : bibliography) {
        ui->bibliographyBLineEdit->insertPlainText(entry + "\n");
    }
}
