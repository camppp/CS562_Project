#include <iostream>
#include <ostream>

class JasminFileGenerator {
public:
    // ... other member variables and functions

    void WriteTo(std::ostream& out){
        out << "// Jasmin file generated by the JasminFileGenerator class" << std::endl;
        out << "// This file contains the bytecode instructions generated by the codeGen function" << std::endl;
        out << "// on the root node of the context" << std::endl;
        out << std::endl;
        out << "// Bytecode instructions:" << std::endl;
        out << "// ..." << std::endl;
    }
};
