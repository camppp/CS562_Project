#include <stdio.h>

void processCommands(FILE *fp) {
    int case_val;
    while (fscanf(fp, "%d", &case_val) != EOF) {
        switch (case_val) {
            case 1:
                fprintf(fp, "*  Blue ");
                break;
            default:
                // Handle any other case_val
                fprintf(fp, "Unknown command ");
                break;
        }
    }
}

int main() {
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    FILE *commandsFile = fopen("commands.txt", "r");
    if (commandsFile == NULL) {
        printf("Error opening commands file.\n");
        return 1;
    }

    processCommands(fp);

    fclose(fp);
    fclose(commandsFile);
    return 0;
}
