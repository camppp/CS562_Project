c
int calculateCharDimensions(FT_Face face, int size, int dpi, int* width, int* height) {
    int error = FT_Set_Char_Size(face, 0, size*64, dpi, dpi);
    if (error) {
        printf("Could not set char size: code %d\n", error);
        return error;
    }

    *width = face->glyph->metrics.horiAdvance / 64;
    *height = face->glyph->metrics.vertAdvance / 64;

    return 0;
}
