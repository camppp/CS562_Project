#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> extractIncludedFiles(const std::string& sourceCode) {
    std::vector<std::string> includedFiles;
    std::regex includeRegex("#include\\s+([\"<])([^\">]+)([\">])");
    std::smatch match;

    auto it = sourceCode.cbegin();
    while (std::regex_search(it, sourceCode.cend(), match, includeRegex)) {
        includedFiles.push_back(match[2].str());
        it = match.suffix().first;
    }

    return includedFiles;
}

int main() {
    std::string sourceCode = R"(
/*=============================================================================
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.
=============================================================================*/

#include "NiftyLinkTrackingDataMessageHelpersTests.h"
#include <NiftyLinkTrackingDataMessageHelpers.h>
#include <NiftyLinkUtils.h>
)";

    std::vector<std::string> result = extractIncludedFiles(sourceCode);
    for (const auto& file : result) {
        std::cout << file << std::endl;
    }

    return 0;
}
