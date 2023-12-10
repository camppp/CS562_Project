class task_t {
public:
    task_t() {}

    int task_create(const char* const pcName, unsigned short usStackDepth = 256, unsigned portBASE_TYPE uxPriority = 2) {
        return xTaskCreate(_task, (signed char *)pcName, usStackDepth, this, uxPriority, NULL);
    }

protected:
    static void _task(void* pvParameters) {
        // Perform the specific action for this task
        // For example, the task could be to toggle an LED
        // Replace the following line with the desired task action
        toggleLED();
    }

    // Example task action to toggle an LED
    void toggleLED() {
        // Code to toggle an LED
    }
};
