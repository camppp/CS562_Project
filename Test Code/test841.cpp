#include <iostream>
#include <unordered_map>
#include <sstream>

class VirtualCPU {
private:
    std::unordered_map<char, int> registers;

public:
    VirtualCPU() {
        for (char reg = 'A'; reg <= 'Z'; ++reg) {
            registers[reg] = 0;
        }
    }

    int executeAssembly(const std::string& assemblyCode) {
        std::istringstream iss(assemblyCode);
        std::string operation, reg;
        int value;

        while (iss >> operation >> reg >> value) {
            if (operation == "set") {
                registers[reg[0]] = value;
            } else if (operation == "add") {
                registers[reg[0]] += value;
            } else if (operation == "sub") {
                registers[reg[0]] -= value;
            } else if (operation == "mul") {
                registers[reg[0]] *= value;
            } else if (operation == "div") {
                registers[reg[0]] /= value;
            } else if (operation == "mod") {
                registers[reg[0]] %= value;
            }
        }

        return registers['A'];
    }
};

int main() {
    VirtualCPU cpu;
    std::string assemblyCode = "set A 256\nadd A 10\nsub B 5\nmul C 2\ndiv A 8\nmod A 7";
    std::cout << "Final value in register A: " << cpu.executeAssembly(assemblyCode) << std::endl;
    return 0;
}
