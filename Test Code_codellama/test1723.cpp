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
        // Implement the logic to execute the instruction
    }

    void reset() override {
        // Implement the logic to reset the CPU
    }
};

} // namespace arch
