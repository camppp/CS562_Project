#include <iostream>
#include <csignal>

namespace mimir {
  extern sig_atomic_t signaled;

  void handleCtrlC(int signal) {
    signaled = 1;
  }

  void performActionOnCtrlC() {
    std::cout << "Ctrl-C signal captured. Performing specific action..." << std::endl;
    // Perform the specific action here
  }
}

int main() {
  mimir::signaled = 0;

  // Set up the signal handler for Ctrl-C
  std::signal(SIGINT, mimir::handleCtrlC);

  // Main program loop
  while (!mimir::signaled) {
    // Perform main program tasks
  }

  // Perform specific action on Ctrl-C signal capture
  mimir::performActionOnCtrlC();

  return 0;
}
