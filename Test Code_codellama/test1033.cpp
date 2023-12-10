bool SaveGraphCutoffsDialogController::validate() {
    // Check if at least one graph cutoff is selected
    if (ac.getSelectedGraphCutoffs().empty()) {
        // Display error message
        QMessageBox::critical(this, "Error", "Please select at least one graph cutoff.");
        return false;
    }

    // Check if each graph cutoff value is a non-negative integer
    for (const auto& cutoff : ac.getSelectedGraphCutoffs()) {
        if (cutoff < 0) {
            // Display error message
            QMessageBox::critical(this, "Error", "Graph cutoff value must be a non-negative integer.");
            return false;
        }
    }

    return true;
}
