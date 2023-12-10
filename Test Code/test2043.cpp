FileBrowserDialog *FileBrowserManager::openOrActivateDialog(const Account &account, const ServerRepo &repo) {
    // Check if a dialog already exists for the specified account and repository
    for (FileBrowserDialog *dialog : activeDialogs) {
        if (dialog->getAccount() == account && dialog->getServerRepo() == repo) {
            // Activate the existing dialog and return its pointer
            dialog->activate();
            return dialog;
        }
    }

    // If no existing dialog found, create a new one and add it to the active dialogs list
    FileBrowserDialog *newDialog = new FileBrowserDialog(account, repo);
    activeDialogs.push_back(newDialog);
    return newDialog;
}
