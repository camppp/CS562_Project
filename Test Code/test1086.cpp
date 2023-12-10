#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int countFiles(const char *path) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    if ((dir = opendir(path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_REG) {
                count++;
            } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char subPath[1024];
                snprintf(subPath, sizeof(subPath), "%s/%s", path, entry->d_name);
                count += countFiles(subPath);
            }
        }
        closedir(dir);
    } else if (errno == ENOENT) {
        fprintf(stderr, "Error: Directory not found\n");
    } else {
        fprintf(stderr, "Error: Unable to open directory\n");
    }

    return count;
}

int main() {
    const char *directoryPath = "/path/to/directory";
    int totalFiles = countFiles(directoryPath);
    printf("Total files in directory: %d\n", totalFiles);
    return 0;
}
