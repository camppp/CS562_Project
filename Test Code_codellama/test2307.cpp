#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, string> parseArgs(const vector<string>& args) {
    map<string, string> options;

    for (int i = 0; i < args.size(); i++) {
        string arg = args[i];

        if (arg == "--search") {
            if (i + 1 >= args.size()) {
                throw ArgError("Missing argument for --search option");
            }
            options["--search"] = args[i + 1];
            i++;
        } else if (arg == "--file") {
            if (i + 1 >= args.size()) {
                throw ArgError("Missing argument for --file option");
            }
            options["--file"] = args[i + 1];
            i++;
        } else if (arg == "--help") {
            cout << "Usage: myprogram [options]" << endl;
            cout << "Options:" << endl;
            cout << "  --search <query>  Indicates a search operation with the specified query" << endl;
            cout << "  --file <filename> Specifies the file to be processed" << endl;
            cout << "  --help            Displays the help message and usage instructions" << endl;
            exit(0);
        } else {
            throw ArgError("Unknown option: " + arg);
        }
    }

    return options;
}
