c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int countFiles(const char *path) {
    DIR *dir;
    struct dirent *ent;
    int totalFiles = 0;

    if ((dir = opendir(path)) == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        return -1;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            totalFiles++;
        } else if (ent->d_type == DT_DIR) {
            totalFiles += countFiles(ent->d_name);
        }
    }

    closedir(dir);
    return totalFiles;
}
