#include <string>
#include <vector>
#include <algorithm>
#include <unicode/coll.h>

int compareStrings(const std::string& str1, const std::string& str2, const std::vector<uint32_t>& table, collation_strength strength) {
    UErrorCode status = U_ZERO_ERROR;
    UCollator *collator = ucol_openRules(table.data(), table.size(), strength, UCOL_DEFAULT, &status);
    if (U_FAILURE(status)) {
        // Handle error in opening collator
        return 0; // or any appropriate error code
    }

    UCollationResult result = ucol_strcollUTF8(collator, str1.c_str(), str1.length(), str2.c_str(), str2.length(), &status);
    ucol_close(collator);

    if (U_FAILURE(status)) {
        // Handle error in string comparison
        return 0; // or any appropriate error code
    }

    if (result == UCOL_LESS) {
        return -1;
    } else if (result == UCOL_EQUAL) {
        return 0;
    } else {
        return 1;
    }
}
