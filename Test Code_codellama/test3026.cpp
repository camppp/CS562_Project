void strcat_pos(char string1[], char string2[], char string_final[], int pos) {
    int i, j;
    for (i = 0; i < pos; i++) {
        string_final[i] = string1[i];
    }
    for (j = 0; j < strlen(string2); j++) {
        string_final[i + j] = string2[j];
    }
    string_final[i + j] = '\0';
}
