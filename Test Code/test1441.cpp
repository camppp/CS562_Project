#include <iostream>
#include <cstdlib>
#include <cstring>

void disp_help(const char* programName) {
    // Implementation of help display logic
}

int main(int argc, char* argv[]) {
    char rangeChar[10]; // Assuming a maximum length for the range character

    int opt;
    while ((opt = getopt(argc, argv, "hr:c:")) != -1) {
        switch (opt) {
            case 'h':
                disp_help(argv[0]);
                return 0;
            case 'r':
                if (1 != sscanf(optarg, "%9s", rangeChar)) {
                    std::cout << "error ==> wrong format of " << optarg << std::endl;
                    // Handle incorrect format error
                } else {
                    // Process the 'r' option argument with the correct format
                }
                break;
            case 'c':
                // Implement the logic to handle the 'c' option
                // Process the 'c' option as required
                break;
            default:
                // Handle unknown options or errors
                break;
        }
    }

    // Additional logic for processing other command-line arguments

    return 0;
}
