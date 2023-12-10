#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <assembly_name>" << endl;
    return 1;
  }

  string assemblyName = argv[1];
  ifstream assemblyFile(assemblyName);
  if (!assemblyFile) {
    cout << "Error: Could not open assembly file " << assemblyName << endl;
    return 1;
  }

  string line;
  while (getline(assemblyFile, line)) {
    if (line.find("AssemblyName") != string::npos) {
      cout << "AssemblyName: " << line << endl;
    } else if (line.find("Version") != string::npos) {
      cout << "Version: " << line << endl;
    } else if (line.find("Culture") != string::npos) {
      cout << "Culture: " << line << endl;
    } else if (line.find("PublicKeyToken") != string::npos) {
      cout << "PublicKeyToken: " << line << endl;
    }
  }

  return 0;
}
