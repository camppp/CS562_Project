int getFileCreationFlag(bool fCreate) {
    if (fCreate) {
        return FILE_CREATE;
    } else {
        return 0;
    }
}
