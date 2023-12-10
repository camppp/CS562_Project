c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPCODES 100

typedef struct
{
    char *pszName;
    int ref;
} OpcodeInfo;

int parseOpcodeFile(const char *filePath, OpcodeInfo *opcodes)
{
    FILE *fp;
    char line[100];
    int numOpcodes = 0;

    fp = fopen(filePath, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filePath);
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *token = strtok(line, " ");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", numOpcodes + 1);
            return -1;
        }

        opcodes[numOpcodes].pszName = token;
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", numOpcodes + 1);
            return -1;
        }

        opcodes[numOpcodes].ref = atoi(token);
        numOpcodes++;
    }

    fclose(fp);
    return numOpcodes;
}
