#include <iostream>
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
        return getCheckpointer(serviceCtx).get();
    }

    // Get the checkpointer for a given operation context
    Checkpointer* get(OperationContext* opCtx) {
        return get(opCtx->getServiceContext());
    }

    // Set the checkpointer for a given service context
    void set(ServiceContext* serviceCtx, std::unique_ptr<Checkpointer> newCheckpointer) {
        // Implementation not provided
    }

    // Save the state of the service
    void saveState() {
        // Implementation to save the state of the service
        std::cout << "State saved" << std::endl;
    }

    // Restore the state of the service using the provided checkpointer
    void restoreState(Checkpointer* checkpointer) {
        // Implementation to restore the state of the service using the provided checkpointer
        std::cout << "State restored" << std::endl;
    }

private:
    std::unique_ptr<Checkpointer> getCheckpointer(ServiceContext* serviceCtx) {
        // Implementation to obtain the checkpointer for the given service context
        return std::make_unique<Checkpointer>();
    }
};
