class PlanetEngine {
public:
    static PlanetEngine* Get() {
        if (sEngine == nullptr) {
            sEngine = new PlanetEngine();
        }
        return sEngine;
    }

    // Delete the copy constructor and assignment operator to prevent duplication
    PlanetEngine(const PlanetEngine&) = delete;
    PlanetEngine& operator=(const PlanetEngine&) = delete;

    // Destructor to release the instance
    ~PlanetEngine() {
        delete sEngine;
        sEngine = nullptr;
    }

private:
    // Private constructor to prevent external instantiation
    PlanetEngine() {}

    static PlanetEngine* sEngine;  // Static pointer to the single instance
};

PlanetEngine* PlanetEngine::sEngine = nullptr;  // Initialize the static pointer

int main() {
    PlanetEngine* engine1 = PlanetEngine::Get();  // Access the singleton instance
    PlanetEngine* engine2 = PlanetEngine::Get();  // Access the same instance

    // engine1 and engine2 point to the same instance of PlanetEngine
    // Further calls to PlanetEngine::Get() will return the same instance
    return 0;
}
