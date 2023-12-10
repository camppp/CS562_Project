class Program {
public:
    Program(const std::string& name) : name(name) {}

    void addInstruction(const std::string& instruction) {
        instructions.push_back(instruction);
    }

    void deleteInstruction(const std::string& instruction) {
        instructions.erase(std::remove(instructions.begin(), instructions.end(), instruction), instructions.end());
    }

    void execute() {
        for (const auto& instruction : instructions) {
            // Execute the instruction
        }
    }

private:
    std::string name;
    std::vector<std::string> instructions;
};
