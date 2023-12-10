CMainControlPanelDlg* AllocateMainControlPanelMemory() {
    CMainControlPanelDlg* allocatedMemory = nullptr;
    try {
        allocatedMemory = new CMainControlPanelDlg;
        if (!allocatedMemory) {
            throw std::bad_alloc();
        }
    } catch (const std::bad_alloc& e) {
        // Handle memory allocation failure
        // Log the error or perform any necessary cleanup
        // Example: 
        // std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        // delete allocatedMemory; // Clean up allocated memory
        allocatedMemory = nullptr; // Set to nullptr to indicate allocation failure
    }
    return allocatedMemory;
}

// Usage
gpMainCtrlPanel = AllocateMainControlPanelMemory();
if (gpMainCtrlPanel) {
    // Proceed with using gpMainCtrlPanel
} else {
    // Handle memory allocation failure
    // Example: display an error message to the user
}
