void* MapFileIntoMemory(HANDLE file_handle) {
  // Create a file mapping object that refers to the file.
  HANDLE file_mapping_object =
      CreateFileMappingA(file_handle, nullptr, PAGE_READONLY, 0, 0, nullptr);
  if (file_mapping_object == NULL) {
    const std::string last_error = GetLastSystemError();
    SAFTM_LOG(ERROR) << "Error while mmapping: " << last_error;
    return nullptr;  // Return nullptr to indicate failure.
  }
  Win32HandleCloser handle_closer(file_mapping_object);

  // Map the file mapping object into memory.
  void *mmap_addr = MapViewOfFile(file_mapping_object, FILE_MAP_READ, 0, 0, 0);
  if (mmap_addr == nullptr) {
    const std::string last_error = GetLastSystemError();
    SAFTM_LOG(ERROR) << "Error while mapping file into memory: " << last_error;
    return nullptr;  // Return nullptr to indicate failure.
  }

  return mmap_addr;  // Return the pointer to the mapped memory.
}
