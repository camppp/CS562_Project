#include <iostream>
#include <string>
#include <map>

using namespace std;

class JITCompiler {
private:
    map<string, int> registers;

public:
    JITCompiler() {
        registers = map<string, int>();
    }

    void load(string register, int memoryAddress) {
        // Load a value from memory into a register
        registers[register] = memoryAddress;
    }

    void store(string register, int memoryAddress) {
        // Store a value from a register into memory
        registers[register] = memoryAddress;
    }

    void add(string register, int constant) {
        // Add a constant to the value in a register
        registers[register] += constant;
    }

    void sub(string register, int constant) {
        // Subtract a constant from the value in a register
        registers[register] -= constant;
    }

    string generateMachineCode() {
        // Generate optimized machine code based on the sequence of instructions
        string machineCode = "";
        for (auto it = registers.begin(); it != registers.end(); it++) {
            machineCode += it->first + " " + it->second + "\n";
        }
        return machineCode;
    }
};

int main() {
    JITCompiler compiler;
    compiler.load("rax", 10);
    compiler.store("rax", 20);
    compiler.add("rax", 30);
    compiler.sub("rax", 40);
    string machineCode = compiler.generateMachineCode();
    cout << machineCode << endl;
    return 0;
}
