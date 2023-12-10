std::map<std::pair<uint16_t, uint16_t>, int8_t> parseKerningTable(const KerningNode* kerningTable, size_t tableSize)
{
    std::map<std::pair<uint16_t, uint16_t>, int8_t> kerningPairs;

    for (size_t i = 0; i < tableSize; i++)
    {
        const KerningNode& node = kerningTable[i];
        kerningPairs.insert(std::make_pair(std::make_pair(node.firstChar, node.firstChar + 1), node.kerningDistance));
    }

    return kerningPairs;
}
