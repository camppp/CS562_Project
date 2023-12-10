#include <iostream>
#include <string>
#include <vector>

class Program {
private:
    std::string name;
    std::vector<std::string> instructions;

public:
    Program(const std::string& programName) : name(programName) {}

    void addInstruction(const std::string& instruction) {
        instructions.push_back(instruction);
    }

    void deleteInstruction(const std::string& instruction) {
        for (auto it = instructions.begin(); it != instructions.end(); ++it) {
            if (*it == instruction) {
                instructions.erase(it);
                break;
            }
        }
    }

    void executeProgram() {
        std::cout << "Executing program: " << name << std::endl;
        for (const auto& instruction : instructions) {
            std::cout << "Executing instruction: " << instruction << std::endl;
            // Execute the instruction
        }
    }
};

int main() {
    Program* prog = new Program("SampleProgram");
    prog->addInstruction("Step 1");
    prog->addInstruction("Step 2");
    prog->addInstruction("Step 3");

    prog->executeProgram();

    prog->deleteInstruction("Step 2");

    prog->executeProgram();

    delete prog;

    return 0;
}
