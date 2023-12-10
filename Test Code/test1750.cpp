#include <ft2build.h>
#include FT_FREETYPE_H

typedef struct {
    double x;
    double y;
    double w;
    double h;
    int pxRange;
} GlyphInfo;

void convertMetricsToDoubleFormat(GlyphInfo glyphs[], FT_Face face, int numGlyphs) {
    for (int id = 0; id < numGlyphs; id++) {
        glyphs[id].x = F26DOT6_TO_DOUBLE(face->glyph->metrics.horiBearingX);
        glyphs[id].y = F26DOT6_TO_DOUBLE(face->glyph->metrics.horiBearingY);
        glyphs[id].w = F26DOT6_TO_DOUBLE(face->glyph->metrics.width);
        glyphs[id].h = F26DOT6_TO_DOUBLE(face->glyph->metrics.height);
        glyphs[id].pxRange = 2;
    }
}
