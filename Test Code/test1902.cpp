bool CloseLinuxHandle(HANDLE driver) {
    int result = close((int)driver);
    if (result == 0) {
        return true;  // Handle closed successfully
    } else {
        // Handle error in closing the handle
        perror("Error closing device handle");
        return false;
    }
}
