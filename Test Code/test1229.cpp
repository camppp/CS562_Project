// THFile struct
struct THFile {
  int isBinary;
  int isAutoSpacing;
};

// Function to reset the THFile object to its default state
void THFile_reset(THFile *self) {
  self->isBinary = 1;
  self->isAutoSpacing = 0;
}

// Function to set the isBinary flag to 1
void THFile_binary(THFile *self) {
  self->isBinary = 1;
}

// Function to set the isBinary flag to 0
void THFile_ascii(THFile *self) {
  self->isBinary = 0;
}

// Function to set the isAutoSpacing flag to 1
void THFile_autoSpacing(THFile *self) {
  self->isAutoSpacing = 1;
}
