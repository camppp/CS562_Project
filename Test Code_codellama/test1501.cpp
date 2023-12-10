aafCharacter* modifyName(aafCharacter* Name_mod) {
    // Check if the name contains the prefix "kAAF"
    if (strstr(Name_mod, "kAAF") != NULL) {
        // Remove the prefix "kAAF" from the name
        aafCharacter* newName = (aafCharacter*)malloc(strlen(Name_mod) - 4 * sizeof(aafCharacter));
        strcpy(newName, Name_mod + 4);
        free(Name_mod);
        Name_mod = newName;
    } else {
        // Add the prefix "kAAF" to the name
        aafCharacter* newName = (aafCharacter*)malloc(strlen(Name_mod) + 4 * sizeof(aafCharacter));
        strcpy(newName, "kAAF");
        strcat(newName, Name_mod);
        free(Name_mod);
        Name_mod = newName;
    }
    return Name_mod;
}
