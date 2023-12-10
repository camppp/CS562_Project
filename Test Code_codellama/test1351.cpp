#include <Windows.h>
#include <string>

class EngineManager {
public:
    EngineManager() : m_hModule(nullptr), m_pEngine(nullptr) {}

    bool LoadDLL(const char* dllPath) {
        m_hModule = LoadLibraryA(dllPath);
        if (m_hModule == nullptr) {
            return false;
        }
        return true;
    }

    bool InstantiateEngine() {
        if (m_hModule == nullptr) {
            return false;
        }
        m_pEngine = (Engine*)GetProcAddress(m_hModule, "CreateEngine");
        if (m_pEngine == nullptr) {
            return false;
        }
        return true;
    }

    void ReleaseEngine() {
        if (m_pEngine != nullptr) {
            m_pEngine->Release();
            m_pEngine = nullptr;
        }
    }

    void UnloadDLL() {
        if (m_hModule != nullptr) {
            FreeLibrary(m_hModule);
            m_hModule = nullptr;
        }
    }

    void PerformEngineOperation() {
        if (m_pEngine == nullptr) {
            return;
        }
        // Perform a basic operation on the engine object
        m_pEngine->DoSomething();
    }

private:
    HMODULE m_hModule;
    Engine* m_pEngine;
};
