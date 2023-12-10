#include <iostream>

class SequenceChecker {
  // Implementation of sequence checker
};

void ProcessWorkerTask(int worker_process_id, content::GlobalFrameRoutingId ancestor_render_frame_host_id) {
  if (!sequence_checker_.CalledOnValidSequence()) {
    std::cerr << "Error: ProcessWorkerTask called on an invalid sequence." << std::endl;
    return;
  }

  std::cout << "Processing task for worker process ID: " << worker_process_id
            << " and ancestor render frame host ID: " << ancestor_render_frame_host_id << std::endl;
  // Perform the task processing
}

int main() {
  // Test the ProcessWorkerTask function
  ProcessWorkerTask(123, 456);
  return 0;
}
