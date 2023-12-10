#include <vector>
#include <string>

namespace reflection {
    struct MethodParamInfo {
        std::string name;
        std::string type;
    };

    struct TemplateParamInfo {
        std::string name;
        std::string type;
    };

    std::string paramsCallDecls(const std::vector<MethodParamInfo>& params) {
        std::string result;
        for (const auto& param : params) {
            result += param.name + " " + param.type + ", ";
        }
        return result.substr(0, result.size() - 2);
    }

    std::string templateParamsFullDecls(const std::vector<TemplateParamInfo>& params) {
        std::string result;
        for (const auto& param : params) {
            result += param.name + " " + param.type + ", ";
        }
        return result.substr(0, result.size() - 2);
    }
}
