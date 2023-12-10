#include <iostream>
#include <string>

int main() {
    std::string codeSnippet = R"(
            } else {
                DPRINTF(OzoneLSQ,"D-Cache: Write Hit on idx:%i !\n",
                        inst->sqIdx);

//                DPRINTF(Activity, "Active st accessing mem hit [sn:%lli]\n",
//                        inst->seqNum);

                if (req->isLLSC()) {
                    // Stx_C does not generate a system port
                    // transaction in the 21264, but that might be
                    // hard to accomplish in this model.
)";

    size_t writeHitPos = codeSnippet.find("D-Cache: Write Hit on idx:");
    size_t activeStPos = codeSnippet.find("Active st accessing mem hit [sn:");

    if (writeHitPos != std::string::npos) {
        size_t endOfLine = codeSnippet.find('\n', writeHitPos);
        std::string writeHitMsg = codeSnippet.substr(writeHitPos, endOfLine - writeHitPos);
        std::cout << writeHitMsg << std::endl;
    }

    if (activeStPos != std::string::npos) {
        size_t endOfLine = codeSnippet.find('\n', activeStPos);
        std::string activeStMsg = codeSnippet.substr(activeStPos, endOfLine - activeStPos);
        std::cout << activeStMsg << std::endl;
    }

    return 0;
}
