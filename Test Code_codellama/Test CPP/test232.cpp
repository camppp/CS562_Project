namespace hpms {
    class SupplierAdapter {};
    class SimulatorAdapter {};
    class NativeAdapter {};

    static bool gContextInitialized = false;
    static SupplierAdapter* gSupplier = nullptr;
    static SimulatorAdapter* gSimulator = nullptr;
    static NativeAdapter* gNative = nullptr;

    void InitializeContext() {
        if (gContextInitialized) {
            // Context is already initialized, do nothing
            return;
        }

        // Initialize the context
        gSupplier = new SupplierAdapter();
        gSimulator = new SimulatorAdapter();
        gNative = new NativeAdapter();

        gContextInitialized = true;
    }

    void HPMS_ASSERT(bool condition, const char* message) {
        if (!condition) {
            // Handle the error
            std::cerr << message << std::endl;
            exit(1);
        }
    }

    SupplierAdapter* GetSupplier() {
        HPMS_ASSERT(gContextInitialized, "Context must be initialized");
        return gSupplier;
    }

    SimulatorAdapter* GetSimulator() {
        HPMS_ASSERT(gContextInitialized, "Context must be initialized");
        return gSimulator;
    }

    NativeAdapter* GetNative() {
        HPMS_ASSERT(gContextInitialized, "Context must be initialized");
        return gNative;
    }
}
