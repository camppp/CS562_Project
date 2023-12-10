FileBrowserDialog* FileBrowserManager::openOrActivateDialog(const Account& account, const ServerRepo& serverRepo) {
    // Check if a file browser dialog already exists for the specified account and server repository
    auto it = dialogs_.find(std::make_pair(account, serverRepo));
    if (it != dialogs_.end()) {
        // Activate the existing file browser dialog
        it->second->activate();
        return it->second;
    }

    // Create a new file browser dialog for the specified account and server repository
    auto dialog = new FileBrowserDialog(account, serverRepo);
    dialogs_.insert(std::make_pair(std::make_pair(account, serverRepo), dialog));
    return dialog;
}
