class task_t {
public:
    task_t(const char* name, int stack_depth, int priority) {
        // Initialize the task with the given name, stack depth, and priority
    }

    virtual void _task() = 0;
};

void task_create(const char* name, int stack_depth, int priority) {
    // Create a new task with the given name, stack depth, and priority
}

void task_run(task_t* task) {
    // Run the given task
}

int main() {
    // Create a new task with the given name, stack depth, and priority
    task_create("my_task", 1024, 5);

    // Run the task
    task_run(task);

    return 0;
}
