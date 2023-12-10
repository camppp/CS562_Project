c
static void proc0(unsigned received, unsigned event)
{
    if (Tsk1) {
        // Process the event
        printf("Processing event %u\n", event);
    } else {
        printf("Task is inactive, cannot process event\n");
    }
}
