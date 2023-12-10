#include <iostream>
#include <vector>
#include <string>
#include <stk/parallel_machine.h>

void processTasksInParallel(stk::communicator& comm, const std::vector<std::string>& task_names_) {
    // Get the rank of the current machine
    int rank = stk::parallel_machine_rank(comm);

    // If the rank is 0, print the task names
    if (rank == 0) {
        std::cout << "Found " << task_names_.size() << " tasks" << std::endl;
        for (const auto& task_name : task_names_) {
            std::cout << "    - " << task_name << std::endl;
        }
    }

    // Process the tasks in parallel
    stk::parallel_for(comm, task_names_.size(), [&](int i) {
        // Do something with the task
        // ...
    });
}
