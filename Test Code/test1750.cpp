c
void convertMetricsToDoubleFormat(GlyphInfo glyphs[], FontFace* face, int numGlyphs) {
    for (int i = 0; i < numGlyphs; i++) {
        GlyphInfo* glyph = &glyphs[i];
        glyph->x = (double)((int64_t)glyph->x * face->unitsPerEm) / (double)face->emSize;
        glyph->y = (double)((int64_t)glyph->y * face->unitsPerEm) / (double)face->emSize;
        glyph->w = (double)((int64_t)glyph->w * face->unitsPerEm) / (double)face->emSize;
        glyph->h = (double)((int64_t)glyph->h * face->unitsPerEm) / (double)face->emSize;
        glyph->pxRange = 2;
    }
}
