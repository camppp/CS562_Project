void initializeFileSystem() {
  if (!FileFS.begin(true)) {
    Serial.println("[Core] File System failed.");
    // Handle the error
    // ...
  }
}
