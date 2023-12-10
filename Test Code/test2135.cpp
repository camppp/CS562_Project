#include <stdio.h>

static int Tsk1 = 1; // 1 for active, 0 for inactive

static void proc0(unsigned received, unsigned event)
{
    if (Tsk1) {
        // Process the event
        printf("Processing event %u\n", event);
    } else {
        printf("Task is inactive, cannot process event\n");
    }
}

int main() {
    // Test the event handling system
    proc0(1, 10); // Should process the event
    Tsk1 = 0; // Deactivate the task
    proc0(0, 20); // Should not process the event
    return 0;
}
