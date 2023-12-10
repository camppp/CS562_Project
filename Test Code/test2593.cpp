#include <map>
#include <utility>

std::map<std::pair<uint16_t, uint16_t>, int8_t> parseKerningTable(const KerningNode* kerningTable, size_t tableSize)
{
    std::map<std::pair<uint16_t, uint16_t>, int8_t> kerningMap;

    for (size_t i = 0; i < tableSize - 1; ++i)
    {
        uint16_t firstChar = kerningTable[i].firstChar;
        uint16_t secondChar = kerningTable[i + 1].firstChar;
        int8_t kerningDist = kerningTable[i].kerningDistance;

        kerningMap[std::make_pair(firstChar, secondChar)] = kerningDist;
    }

    // Handle the last character in the kerning table
    uint16_t lastChar = kerningTable[tableSize - 1].firstChar;
    kerningMap[std::make_pair(lastChar, 0xFFFF)] = 0;  // Assuming 0xFFFF represents the end of the kerning table

    return kerningMap;
}
