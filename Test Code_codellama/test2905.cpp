#include <tclap/CmdLine.h>

int main(int argc, char* argv[]) {
  // Initialize the command-line parser
  TCLAP::CmdLine cmd("My program", ' ', "1.0");

  // Add the input type argument
  TCLAP::SwitchArg inputTypeArg("i", "inputType", "Specify the type of input (vector fields or images)", false);
  cmd.add(inputTypeArg);

  // Add the error type argument
  TCLAP::SwitchArg errorTypeArg("e", "errorType", "Specify the type of error calculation (squared difference or absolute difference)", false);
  cmd.add(errorTypeArg);

  // Parse the command-line arguments
  cmd.parse(argc, argv);

  // Check if the input type argument was provided
  if (inputTypeArg.getValue()) {
    // Process vector fields
    // ...
  } else {
    // Process images
    // ...
  }

  // Check if the error type argument was provided
  if (errorTypeArg.getValue()) {
    // Calculate squared difference
    // ...
  } else {
    // Calculate absolute difference
    // ...
  }

  return 0;
}
