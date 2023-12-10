#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to extract local variables and Vim settings from a code snippet
void extract_local_variables_and_vim_settings(const string& code_snippet, vector<string>& local_variables, vector<string>& vim_settings) {
    // Split the code snippet into lines
    vector<string> lines = split(code_snippet, "\n");

    // Iterate over the lines and extract local variables and Vim settings
    for (int i = 0; i < lines.size(); i++) {
        // Check if the line contains a local variable
        if (lines[i].find("Local Variables:") != string::npos) {
            // Extract the local variables from the line
            vector<string> local_variables_line = split(lines[i], " ");
            for (int j = 0; j < local_variables_line.size(); j++) {
                if (local_variables_line[j].find(":") != string::npos) {
                    local_variables.push_back(local_variables_line[j]);
                }
            }
        }

        // Check if the line contains a Vim setting
        if (lines[i].find("Vim Settings:") != string::npos) {
            // Extract the Vim settings from the line
            vector<string> vim_settings_line = split(lines[i], " ");
            for (int j = 0; j < vim_settings_line.size(); j++) {
                if (vim_settings_line[j].find(":") != string::npos) {
                    vim_settings.push_back(vim_settings_line[j]);
                }
            }
        }
    }
}

int main() {
    // Test the function with a code snippet
    string code_snippet = "} \n\n/* \n  Local Variables: \n  mode:c++ \n  c-file-style:\"stroustrup\" \n  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +)) \n  indent-tabs-mode:nil \n  fill-column:99 \n  End: \n*/ \n// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:fileencoding=utf-8:textwidth=99 :";
    vector<string> local_variables;
    vector<string> vim_settings;
    extract_local_variables_and_vim_settings(code_snippet, local_variables, vim_settings);

    // Print the extracted local variables and Vim settings
    cout << "Local Variables:" << endl;
    for (int i = 0; i < local_variables.size(); i++) {
        cout << local_variables[i] << endl;
    }
    cout << "Vim Settings:" << endl;
    for (int i = 0; i < vim_settings.size(); i++) {
        cout << vim_settings[i] << endl;
    }

    return 0;
}
