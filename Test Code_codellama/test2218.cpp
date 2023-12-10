#include <memory>

class ServiceContext {
    // Implementation details not provided
};

class OperationContext {
public:
    ServiceContext* getServiceContext() {
        // Implementation details not provided
    }
};

class Checkpointer {
public:
    // Get the checkpointer for a given service context
    Checkpointer* get(ServiceContext* serviceCtx) {
        // Implementation details not provided
    }

    // Get the checkpointer for a given operation context
    Checkpointer* get(OperationContext* opCtx) {
        // Implementation details not provided
    }

    // Set the checkpointer for a given service context
    void set(ServiceContext* serviceCtx, std::unique_ptr<Checkpointer> newCheckpointer) {
        // Implementation details not provided
    }

    // Save the state of the service
    void saveState() {
        // Implementation details not provided
    }

    // Restore the state of the service using the provided checkpointer
    void restoreState(Checkpointer* checkpointer) {
        // Implementation details not provided
    }
};
