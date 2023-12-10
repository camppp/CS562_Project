#include <vector>
#include <string>
#include <sstream>

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
        std::stringstream ss;
        for (size_t i = 0; i < params.size(); ++i) {
            ss << params[i].type << " " << params[i].name;
            if (i < params.size() - 1) {
                ss << ", ";
            }
        }
        return ss.str();
    }

    std::string templateParamsFullDecls(const std::vector<TemplateParamInfo>& params) {
        std::stringstream ss;
        ss << "<";
        for (size_t i = 0; i < params.size(); ++i) {
            ss << params[i].type << " " << params[i].name;
            if (i < params.size() - 1) {
                ss << ", ";
            }
        }
        ss << ">";
        return ss.str();
    }
}
