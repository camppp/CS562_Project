class CallStack {
private:
    std::vector<FunctionFrame> frames;

public:
    void pushStack(int frameSize, int argumentCount, void* function, void* destination, void* instructions) {
        frames.push_back(FunctionFrame(frameSize, argumentCount, function, destination, instructions));
    }

    void popStack() {
        frames.pop_back();
    }

    void runFunctionPointerBlock() {
        // Execute the function pointer block
    }
};

class FunctionFrame {
private:
    int frameSize;
    int argumentCount;
    void* function;
    void* destination;
    void* instructions;

public:
    FunctionFrame(int frameSize, int argumentCount, void* function, void* destination, void* instructions) {
        this->frameSize = frameSize;
        this->argumentCount = argumentCount;
        this->function = function;
        this->destination = destination;
        this->instructions = instructions;
    }
};
