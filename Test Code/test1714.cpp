#include <iostream>
#include <vector>
#include "parallel_utility.h"  // Assume the parallel utility library is included

void processTasksInParallel(const CommunicationInterface& comm, const std::vector<std::string>& task_names_) {
    if (stk::parallel_machine_rank(comm) == 0) {
        std::cout << "Found " << task_names_.size() << " tasks\n";
        for (const auto& task : task_names_) {
            std::cout << "    - " << task << "\n";
        }
        std::cout << std::endl;
    }
}
