++
int getDownloadProgress(UpdateStatus status, int downloadProgress) {
  if (status == UpdateStatus::UPDATE_STATUS_ERROR) {
    return 0;  // Error state, download progress is 0
  } else if (status == UpdateStatus::UPDATE_STATUS_VERIFYING ||
             status == UpdateStatus::UPDATE_STATUS_FINALIZING ||
             status == UpdateStatus::UPDATE_STATUS_NEED_REBOOT) {
    return 0;  // Download progress remains at 0 during these phases
  } else {
    return downloadProgress;  // For all other phases, return the input download progress
  }
}
