SpriteData parseSprite(FILE *fp, const char *name) {
    SpriteData sprite;
    char line[100];

    // Read the first line of the sprite block
    fgets(line, sizeof(line), fp);

    // Check if the line contains the texture name
    if (strstr(line, "texture =") != NULL) {
        // Extract the texture name
        char *texture = strtok(line, " =");
        strcpy(sprite.texture, texture);
    }

    // Read the next line of the sprite block
    fgets(line, sizeof(line), fp);

    // Check if the line contains the rectangle coordinates
    if (strstr(line, "rect =") != NULL) {
        // Extract the rectangle coordinates
        char *coords = strtok(line, " =");
        char *x = strtok(coords, ",");
        char *y = strtok(NULL, ",");
        char *width = strtok(NULL, ",");
        char *height = strtok(NULL, ",");

        // Convert the coordinates to integers
        sprite.x = atoi(x);
        sprite.y = atoi(y);
        sprite.width = atoi(width);
        sprite.height = atoi(height);
    }

    // Ignore any additional data in the sprite block

    // Return the parsed sprite data
    return sprite;
}
