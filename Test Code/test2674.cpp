#include <vector>

const unsigned maxFallbackPerCharacter = 3;
static const UChar32 characterFallback[][maxFallbackPerCharacter] = {
    { 0x005E, 0x0302, 0 }, // CIRCUMFLEX ACCENT
    { 0x005F, 0x0332, 0 }, // LOW LINE
    { 0x007E, 0x0303, 0 }, // TILDE
    { 0x00AF, 0x0304, 0x0305 }, // MACRON
    { 0x02C6, 0x0302, 0 }, // MODIFIER LETTER CIRCUMFLEX ACCENT
    { 0x02C7, 0x030C, 0 } // CARON
};
const unsigned characterFallbackSize = WTF_ARRAY_LENGTH(characterFallback);

std::vector<UChar32> getCharacterFallback(UChar32 inputCharacter) {
    std::vector<UChar32> fallbackCharacters;
    for (unsigned i = 0; i < characterFallbackSize; ++i) {
        if (characterFallback[i][0] == inputCharacter) {
            for (unsigned j = 0; j < maxFallbackPerCharacter; ++j) {
                if (characterFallback[i][j] != 0) {
                    fallbackCharacters.push_back(characterFallback[i][j]);
                } else {
                    break;
                }
            }
            break;
        }
    }
    return fallbackCharacters;
}
