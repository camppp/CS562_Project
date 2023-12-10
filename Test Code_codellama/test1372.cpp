#include <functional>

class FunctionManager {
public:
    FunctionManager() : execution_(true), readDuringExecution_(false) {}

    void execute(const std::function<void()>& func) {
        if (execution_) {
            func();
            if (readDuringExecution_) {
                readDuringExecution_ = false;
            }
        }
    }

    void read() {
        if (execution_) {
            readDuringExecution_ = true;
        }
    }

    void setExecution(bool execute) {
        execution_ = execute;
    }

private:
    bool execution_;
    bool readDuringExecution_;
};
