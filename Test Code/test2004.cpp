#include <stdio.h>
#include <string.h>

int get_args_list(const char* command, char* arg_list[]) {
    int arg_count = 0;
    const char* delimiters = " \n";
    char* token = strtok((char*)command, delimiters);

    while (token != NULL && arg_count < 128) {
        if (token[0] == '"') {
            // Argument enclosed within double quotes
            int len = strlen(token);
            if (token[len - 1] == '"') {
                // Single argument enclosed within double quotes
                token[len - 1] = '\0';  // Remove ending quote
                arg_list[arg_count++] = token + 1;  // Add argument without starting quote
            } else {
                // Argument starts with double quotes but continues in subsequent tokens
                char* arg = token + 1;  // Start of the argument without starting quote
                while ((token = strtok(NULL, "\"")) != NULL) {
                    arg = strcat(arg, " ");  // Append space
                    arg = strcat(arg, token);  // Append next token
                    if (token[strlen(token) - 1] == '"') {
                        arg_list[arg_count++] = arg;  // Add complete argument
                        break;
                    }
                }
            }
        } else {
            // Regular argument without quotes
            arg_list[arg_count++] = token;
        }
        token = strtok(NULL, delimiters);
    }

    return arg_count;
}
