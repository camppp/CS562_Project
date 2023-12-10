#include <ft2build.h>
#include FT_FREETYPE_H

int calculateCharDimensions(FT_Face face, int size, int dpi, int* width, int* height) {
  FT_Error error = FT_Set_Char_Size(face, 0, size*64, dpi, dpi);
  if (error) {
    printf("Could not set char size: code %d\n", error);
    return error;
  }

  *width = face->size->metrics.max_advance / 64;
  *height = face->size->metrics.height / 64;

  return 0;
}
