c++
int getDownloadProgress(UpdateStatus status, int downloadProgress) {
    if (status == UpdateStatus::UPDATE_STATUS_DOWNLOADING) {
        return downloadProgress;
    } else if (status == UpdateStatus::UPDATE_STATUS_VERIFYING ||
               status == UpdateStatus::UPDATE_STATUS_FINALIZING ||
               status == UpdateStatus::UPDATE_STATUS_NEED_REBOOT) {
        return 0;
    } else {
        return 1;
    }
}
