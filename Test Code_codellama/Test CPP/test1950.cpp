class Warning {
public:
    // Constructor
    Warning(const std::string& misra) : misra(misra) {}

    // GetMISRAStringWithLanguagePrefix function
    std::string GetMISRAStringWithLanguagePrefix() {
        if (misra.find("-") != std::string::npos) {
            return "MISRAPrefixCPlusPlus" + misra;
        } else if (misra.find(".") != std::string::npos) {
            return "MISRAPrefixC" + misra;
        } else {
            return "";
        }
    }

    // HasCWE function
    bool HasCWE() {
        return misra.find("CWE") != std::string::npos;
    }

private:
    std::string misra;
};
