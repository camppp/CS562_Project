#include <iostream>
#include <vector>
#include <memory>

class LoopParallelInfo;
class TargetParallelInfo;

class LoopAnalyserBase {
public:
    std::shared_ptr<TargetParallelInfo> analyse(const LoopParallelInfo& loopParallelInfo) {
        // Check if the loop is a basic block
        if (loopParallelInfo.isBasicBlock()) {
            // Perform basic analysis on the loop
            // ...

            // Create and return the appropriate TargetParallelInfo object
            return std::make_shared<TargetParallelInfo>(loopParallelInfo.getTarget());
        } else {
            // Perform additional analysis or checks on the non-basic block loop
            // ...

            // Create and return the appropriate TargetParallelInfo object
            return std::make_shared<TargetParallelInfo>(loopParallelInfo.getTarget());
        }
    }
};
