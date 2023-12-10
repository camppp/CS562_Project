#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPCODES 100

typedef struct
{
    char *pszName;
    int ref;
} OpcodeInfo;

int parseOpcodeFile(const char *filePath, OpcodeInfo *opcodes) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    int count = 0;
    char opcodeName[50];
    int opcodeRef;

    while (fscanf(file, "%s %d", opcodeName, &opcodeRef) == 2 && count < MAX_OPCODES) {
        opcodes[count].pszName = strdup(opcodeName);
        opcodes[count].ref = opcodeRef;
        count++;
    }

    fclose(file);
    return count;
}
