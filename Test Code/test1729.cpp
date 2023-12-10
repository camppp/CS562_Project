#include <iostream>
#include <filesystem>

TInt64 CliTask::command_lsahci(TInt ac, char **av) {
  if (ac != 2) {
    Error("lsahci expects exactly one argument");
    return -1;  // Return an error code to indicate failure
  }

  std::string directoryPath = av[1];  // Get the directory path from the command-line argument

  if (!std::filesystem::exists(directoryPath)) {
    Error("Directory does not exist");
    return -1;  // Return an error code to indicate failure
  }

  if (!std::filesystem::is_directory(directoryPath)) {
    Error("Not a directory");
    return -1;  // Return an error code to indicate failure
  }

  mWindow->WriteFormatted("Contents of directory '%s':\n", directoryPath.c_str());

  for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
    mWindow->WriteFormatted("%s\n", entry.path().filename().string().c_str());
  }

  return 0;  // Return 0 to indicate successful execution
}
