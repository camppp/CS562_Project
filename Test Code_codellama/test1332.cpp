class PlanetEngine {
private:
    // Private constructor to prevent external instantiation
    PlanetEngine() {}

    // Private destructor to prevent external destruction
    ~PlanetEngine() {}

public:
    // Static method to get the instance of the PlanetEngine
    static PlanetEngine* Get() {
        // Check if the instance already exists
        if (instance == nullptr) {
            // If not, create a new instance
            instance = new PlanetEngine();
        }
        return instance;
    }

private:
    // Global instance of the PlanetEngine
    static PlanetEngine* instance;
};

// Implementation of the Get() method
PlanetEngine* PlanetEngine::Get() {
    if (instance == nullptr) {
        instance = new PlanetEngine();
    }
    return instance;
}

// Implementation of the destructor
PlanetEngine::~PlanetEngine() {
    // Delete the instance if it exists
    if (instance != nullptr) {
        delete instance;
    }
}

// Implementation of the private constructor
PlanetEngine::PlanetEngine() {}

// Implementation of the private destructor
PlanetEngine::~PlanetEngine() {}
