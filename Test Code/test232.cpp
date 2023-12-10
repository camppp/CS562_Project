namespace hpms {
    class SupplierAdapter {};
    class SimulatorAdapter {};
    class NativeAdapter {};

    static bool gContextInitialized = false;
    static SupplierAdapter* gSupplier = nullptr;
    static SimulatorAdapter* gSimulator = nullptr;
    static NativeAdapter* gNative = nullptr;

    void InitializeContext() {
        if (!gContextInitialized) {
            // Perform context initialization
            gSupplier = new SupplierAdapter();
            gSimulator = new SimulatorAdapter();
            gNative = new NativeAdapter();
            gContextInitialized = true;
        }
    }

    void HPMS_ASSERT(bool condition, const char* message) {
        if (!condition) {
            throw std::runtime_error(message);
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
