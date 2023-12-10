#include <iostream>
#include <string>

namespace arch {
    class CpuInterface {
    public:
        virtual void executeInstruction(const std::string& instruction) = 0;
        virtual void reset() = 0;
    };

    class MyCpu : public CpuInterface {
    public:
        void executeInstruction(const std::string& instruction) override {
            // Implement the execution of the instruction
            std::cout << "Executing instruction: " << instruction << std::endl;
        }

        void reset() override {
            // Implement the reset functionality
            std::cout << "Resetting CPU" << std::endl;
        }
    };
}

int main() {
    arch::MyCpu cpu;
    cpu.executeInstruction("MOV R1, R2");
    cpu.reset();
    return 0;
}
