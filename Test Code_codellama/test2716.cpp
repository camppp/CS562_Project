double ParamParser::GetDouble(LPCTSTR name, double defaultVal)
{
    auto it = m_params.find(name);
    if (it != m_params.end())
    {
        try
        {
            return ParseData<double>(it->second.c_str());
        }
        catch (const std::exception&)
        {
            return defaultVal;
        }
    }
    return defaultVal;
}
