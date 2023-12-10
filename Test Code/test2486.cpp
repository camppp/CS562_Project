#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char texture[50];
    int x, y, width, height;
} SpriteData;

SpriteData parseSprite(FILE *fp, const char *name) {
    SpriteData sprite;
    char line[100];
    char texture[50];
    int x, y, width, height;

    // Read lines until the end of the sprite block
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, " texture = %s", texture) == 1) {
            strcpy(sprite.texture, texture);
        } else if (sscanf(line, " rect = %d,%d,%d,%d", &x, &y, &width, &height) == 4) {
            sprite.x = x;
            sprite.y = y;
            sprite.width = width;
            sprite.height = height;
            break;  // Exit loop after extracting required data
        }
    }

    strcpy(sprite.name, name);  // Set the name of the sprite

    return sprite;
}
