#include <iostream>
#include <cstdlib>

int spx() {
  // Execute a system process using appropriate system calls
  int exitStatus = system("ls");

  // Return the exit status of the executed system process
  return exitStatus;
}
