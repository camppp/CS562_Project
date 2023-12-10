#include <FileFS.h>
#include <Serial.h>

void setup() {
  // Other setup code
  initializeFileSystem();
  // Other setup code
}

void initializeFileSystem() {
  if (!FileFS.begin(true)) {
    Serial.println("[Core] File System failed.");
  }
}
