TInt64 CliTask::command_lsahci(TInt ac, char **av)
{
    // Validate the number of arguments
    if (ac != 2)
    {
        printf("Error: Invalid number of arguments\n");
        return 1;
    }

    // Get the directory name from the argument vector
    char *directoryName = av[1];

    // List the contents of the directory
    TInt64 result = listDirectory(directoryName);

    // Print the result
    printf("Directory contents:\n");
    for (TInt i = 0; i < result.size(); i++)
    {
        printf("%s\n", result[i]);
    }

    return 0;
}
