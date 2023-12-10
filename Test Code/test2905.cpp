#include <iostream>
#include <tclap/CmdLine.h>

int main(int argc, char** argv) {
  try {
    TCLAP::CmdLine cmd("Command description message", ' ', "0.9");

    TCLAP::SwitchArg vecSwitchArg("v", "vectorFields", "inputs are vector fields, not images", cmd, false);
    TCLAP::SwitchArg sqrErrArg("s", "squaredError", "use squared difference", cmd, false);

    TCLAP::SwitchArg inputTypeArg("i", "inputType", "specify the type of input (vector fields)", false);
    TCLAP::SwitchArg errorTypeArg("e", "errorType", "specify the type of error calculation (squared difference)", false);

    cmd.add(inputTypeArg);
    cmd.add(errorTypeArg);

    cmd.parse(argc, argv);

    bool processVectorFields = vecSwitchArg.getValue() || inputTypeArg.getValue();
    bool useSquaredError = sqrErrArg.getValue() || errorTypeArg.getValue();

    if (processVectorFields) {
      std::cout << "Processing vector fields" << std::endl;
    } else {
      std::cout << "Processing images" << std::endl;
    }

    if (useSquaredError) {
      std::cout << "Using squared difference for error calculation" << std::endl;
    } else {
      std::cout << "Using absolute difference for error calculation" << std::endl;
    }
  } catch (TCLAP::ArgException &e) {
    std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
  }
  return 0;
}
