double ParamParser::GetDouble(LPCTSTR name, double defaultVal)
{
    // look for the param name
    std::map<StrType, StrType>::iterator pos = m_params.find(name);
    
    // lookup the param name
    if (pos != m_params.end())
    {
        // if data parsing fails this function will return default value
        // Assuming ParseData is a template function that can parse a string to the specified data type
        // ON_ERROR_CONTINUE(InvalidParameterException, return ParseData<double>(pos->second.c_str()));
        try {
            return ParseData<double>(pos->second.c_str());
        } catch (InvalidParameterException& e) {
            return defaultVal;
        }
    }
    return defaultVal;
}
