#include <string>
#include <iostream>

class Warning {
private:
    std::string misra;
    static const std::string MISRAPrefixCPlusPlus;
    static const std::string MISRAPrefixC;

public:
    std::string GetMISRAStringWithLanguagePrefix() const {
        if (misra.find('-') != std::string::npos)
            return MISRAPrefixCPlusPlus + misra;
        else if (misra.find('.') != std::string::npos)
            return MISRAPrefixC + misra;
        else
            return "";
    }

    bool HasCWE() const {
        return (misra.find("CWE") != std::string::npos);
    }
};

const std::string Warning::MISRAPrefixCPlusPlus = "C++ ";
const std::string Warning::MISRAPrefixC = "C ";

int main() {
    Warning warning1;
    warning1.misra = "MISRA-C++-2008";
    std::cout << warning1.GetMISRAStringWithLanguagePrefix() << std::endl;  // Output: C++ MISRA-C++-2008
    std::cout << warning1.HasCWE() << std::endl;  // Output: 0 (false)

    Warning warning2;
    warning2.misra = "MISRA.C.2004";
    std::cout << warning2.GetMISRAStringWithLanguagePrefix() << std::endl;  // Output: C MISRA.C.2004
    std::cout << warning2.HasCWE() << std::endl;  // Output: 0 (false)

    Warning warning3;
    warning3.misra = "MISRA-2004";
    std::cout << warning3.GetMISRAStringWithLanguagePrefix() << std::endl;  // Output: C++ MISRA-2004
    std::cout << warning3.HasCWE() << std::endl;  // Output: 0 (false)

    Warning warning4;
    warning4.misra = "MISRA-CWE-119";
    std::cout << warning4.GetMISRAStringWithLanguagePrefix() << std::endl;  // Output: C++ MISRA-CWE-119
    std::cout << warning4.HasCWE() << std::endl;  // Output: 1 (true)

    return 0;
}
