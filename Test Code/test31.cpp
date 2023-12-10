#include <memory>
#include <string>
#include <Windows.h> // Assuming Windows platform for LoadLibraryEx

struct Module {
    // Define module structure if needed
};

void LoadModule(std::shared_ptr<Module>& m_module, bool m_AlternativeLoad, const std::string& m_name) {
    if (!m_module && m_AlternativeLoad && IsAbsolutePath(m_name)) {
        m_module.reset(LoadLibraryEx(m_name.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH));
    }
}
