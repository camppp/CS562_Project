bool SaveGraphCutoffsDialogController::validate() {
    // Check if at least one graph cutoff is selected
    if (selectedGraphCutoffs.empty()) {
        QMessageBox::critical(this, tr("Error!"), "Please select at least one graph cutoff");
        return false;
    }

    // Check if each graph cutoff value is a non-negative integer
    for (int cutoff : selectedGraphCutoffs) {
        if (cutoff < 0) {
            QMessageBox::critical(this, tr("Error!"), "Graph cutoff value must be a non-negative integer");
            return false;
        }
    }

    return true;  // Input is valid
}
