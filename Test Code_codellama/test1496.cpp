c
FILE* openFileForWriting(const char* azFileName)
{
    FILE* mpFile = NULL;
    errno_t err = fopen_s(&mpFile, azFileName, "wb");

    if (err != 0)
    {
        printf("Error opening file %s for writing: %s\n", azFileName, strerror(err));
        return NULL;
    }

    return mpFile;
}
