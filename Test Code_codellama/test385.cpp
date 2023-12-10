class CToolFrameworkServer
{
public:
    void FrameUpdatePreEntityThink()
    {
        // Perform any necessary pre-entity update tasks for the tools
        printf("Performing pre-entity update tasks for tools\n");
    }

    void LevelShutdownPostEntityAllTools()
    {
        // Perform any cleanup or shutdown tasks for the tools
        printf("Performing post-entity shutdown tasks for tools\n");
    }
};
