void LoadModule(std::shared_ptr<Module>& m_module, bool m_AlternativeLoad, const std::string& m_name)
{
    // Check if the module is not already loaded
    if (!m_module)
    {
        // Check if an alternative load method is available
        if (m_AlternativeLoad)
        {
            // Check if the module path is an absolute path
            if (IsAbsolutePath(m_name))
            {
                // Load the module using the alternative load method
                m_module.reset(LoadLibraryEx(m_name.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH));
            }
        }
    }
}
