#include <string>
#include <windows.h>

class dll::Handler {
public:
    // Constructor
    Handler(const std::string& libpath) : m_libpath(libpath) {}

    // Move assignment operator
    Handler(Handler&& other) noexcept : m_handler(other.m_handler), m_libpath(other.m_libpath) {}

    // Load method
    bool load() {
        m_handler = LoadLibrary(m_libpath.c_str());
        return m_handler != nullptr;
    }

    // Unload method
    void unload() {
        if (m_handler != nullptr) {
            FreeLibrary(m_handler);
            m_handler = nullptr;
        }
    }

    // Get function method
    template <typename T>
    T getFunction(const std::string& funcName) {
        if (m_handler == nullptr) {
            return nullptr;
        }

        T funcPtr = reinterpret_cast<T>(GetProcAddress(m_handler, funcName.c_str()));
        if (funcPtr == nullptr) {
            return nullptr;
        }

        return funcPtr;
    }

private:
    HMODULE m_handler;
    std::string m_libpath;
};
