int compareStrings(const std::string& str1, const std::string& str2, const std::vector<uint32_t>& table, collation_strength strength) {
    // Convert the input strings to UTF-32
    auto const str1_view = as_utf32(str1);
    auto const str2_view = as_utf32(str2);

    // Iterate over the characters in the input strings
    for (auto it1 = str1_view.begin(), it2 = str2_view.begin(); it1 != str1_view.end() && it2 != str2_view.end(); ++it1, ++it2) {
        // Get the current character from the input strings
        auto const c1 = *it1;
        auto const c2 = *it2;

        // Check if the characters are equal
        if (c1 == c2) {
            continue;
        }

        // Check if the characters are in the custom collation table
        auto const it = std::find(table.begin(), table.end(), c1);
        if (it != table.end()) {
            // The character is in the custom collation table, so compare it with the other character
            auto const it2 = std::find(table.begin(), table.end(), c2);
            if (it2 != table.end()) {
                // Both characters are in the custom collation table, so compare them
                return compareChars(c1, c2, strength);
            }
        }

        // The characters are not in the custom collation table, so compare them using the default collation strength
        return compareChars(c1, c2, strength);
    }

    // The input strings are equal
    return 0;
}

int compareChars(uint32_t c1, uint32_t c2, collation_strength strength) {
    // Compare the characters using the specified collation strength
    switch (strength) {
        case collation_strength::primary:
            return c1 < c2 ? -1 : c1 > c2 ? 1 : 0;
        case collation_strength::secondary:
            return c1 < c2 ? -1 : c1 > c2 ? 1 : 0;
        case collation_strength::tertiary:
            return c1 < c2 ? -1 : c1 > c2 ? 1 : 0;
        case collation_strength::quaternary:
            return c1 < c2 ? -1 : c1 > c2 ? 1 : 0;
        default:
            return c1 < c2 ? -1 : c1 > c2 ? 1 : 0;
    }
}
