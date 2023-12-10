#include <functional>

class FunctionManager {
private:
    bool execution_;
    bool readDuringExecution_;

public:
    FunctionManager() : execution_(true), readDuringExecution_(false) {}

    void execute(const std::function<void()>& func) {
        bool prevReadDuringExecution = readDuringExecution_;
        readDuringExecution_ = false;  // Reset readDuringExecution_ before executing func
        func();
        if (execution_ && readDuringExecution_) {
            readDuringExecution_ = true;  // Set readDuringExecution_ to true if read() was called during execution
        } else {
            readDuringExecution_ = prevReadDuringExecution;  // Restore previous value if read() was not called during execution
        }
    }

    void read() {
        if (execution_) {
            readDuringExecution_ = true;  // Set readDuringExecution_ to true if read() is called during execution
        }
    }

    void setExecution(bool execute) {
        execution_ = execute;  // Set the value of execution_
    }
};
