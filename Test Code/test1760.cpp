#include <iostream>
#include <string>

// Define the DPRINTF macro
#define DPRINTF(fmt, ...) printf(fmt, __VA_ARGS__)

int main() {
    // Define the code snippet as a string
    std::string code = "if (idx == 0) { \n"
                       "    DPRINTF(\"Write Hit on idx:%i !\\n\", idx); \n"
                       "} else { \n"
                       "    // DPRINTF(\"Active st accessing mem hit [sn:%lli]\\n\", sn); \n"
                       "}";

    // Extract the message printed by the DPRINTF macro in the else block
    std::string message = code.substr(code.find("DPRINTF(\"Write Hit on idx:%i !\\n\", idx);") + 19);
    message = message.substr(0, message.find("}"));

    // Extract the commented-out message inside the if block
    std::string commented_message = code.substr(code.find("// DPRINTF(\"Active st accessing mem hit [sn:%lli]\\n\", sn);") + 19);
    commented_message = commented_message.substr(0, commented_message.find("}"));

    // Print the extracted information
    std::cout << "Write Hit on idx:" << idx << " !" << std::endl;
    std::cout << "Active st accessing mem hit [sn:" << sn << "]" << std::endl;

    return 0;
}
