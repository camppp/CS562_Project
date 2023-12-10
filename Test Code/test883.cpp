void addBibliographyEntry(UserInterface* ui, const std::string& bibliographyEntry) {
    // Add the new bibliography entry to the program's data structure
    programDataStructure.addEntry(bibliographyEntry);

    // Update the user interface to display the updated bibliography
    ui->bibliographyBLineEdit->clear();  // Clear the existing content
    for (const auto& entry : programDataStructure.getAllEntries()) {
        ui->bibliographyBLineEdit->insertPlainText(entry + "\n");  // Insert each entry with a new line
    }
}
