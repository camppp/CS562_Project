#include <iostream>
#include <string>
#include <windows.h>

namespace dll {
    class Handler {
    public:
        Handler() : m_handler(nullptr) {}

        Handler(Handler&& o) noexcept :
            m_handler(std::exchange(o.m_handler, nullptr)),
            m_libpath(std::move(o.m_libpath)) {}

        Handler& operator=(Handler&& o) noexcept {
            if (this != &o) {
                unload();
                m_handler = std::exchange(o.m_handler, nullptr);
                m_libpath = std::move(o.m_libpath);
            }
            return *this;
        }

        ~Handler() {
            unload();
        }

        bool load() {
            if (m_handler != nullptr) {
                std::cerr << "DLL already loaded." << std::endl;
                return false;
            }
            m_handler = LoadLibrary(m_libpath.c_str());
            if (m_handler == nullptr) {
                std::cerr << "Failed to load DLL." << std::endl;
                return false;
            }
            return true;
        }

        void unload() {
            if (m_handler != nullptr) {
                FreeLibrary(m_handler);
                m_handler = nullptr;
            }
        }

        template <typename FuncType>
        FuncType* getFunction(const std::string& functionName) {
            if (m_handler != nullptr) {
                return reinterpret_cast<FuncType*>(GetProcAddress(m_handler, functionName.c_str()));
            }
            return nullptr;
        }

    private:
        HMODULE m_handler;
        std::string m_libpath;
    };
}
