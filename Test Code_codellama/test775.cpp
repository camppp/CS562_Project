#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Il2CppTypeDefinitionSizes {
    size_t size;
    size_t alignment;
    size_t type;
};

map<string, string> parseIl2CppTypeDefinitionSizes(const string& code) {
    map<string, string> result;

    // Find the first occurrence of "extern const Il2CppTypeDefinitionSizes"
    size_t pos = code.find("extern const Il2CppTypeDefinitionSizes");
    if (pos == string::npos) {
        return result;
    }

    // Find the first occurrence of "="
    pos = code.find("=", pos);
    if (pos == string::npos) {
        return result;
    }

    // Find the first occurrence of "{"
    pos = code.find("{", pos);
    if (pos == string::npos) {
        return result;
    }

    // Find the first occurrence of "}"
    size_t endPos = code.find("}", pos);
    if (endPos == string::npos) {
        return result;
    }

    // Extract the name of the structure
    string name = code.substr(pos + 1, endPos - pos - 1);
    result["name"] = name;

    // Extract the size of the structure
    string size = code.substr(endPos + 1, code.size() - endPos - 1);
    result["size"] = size;

    // Extract the type of the structure
    string type = code.substr(endPos + 1, code.size() - endPos - 1);
    result["type"] = type;

    return result;
}

int main() {
    string code = "extern const Il2CppTypeDefinitionSizes g_typeDefinitionSize3693 = { sizeof (GdipImageCodecInfo_t2577501090)+ sizeof (Il2CppObject), sizeof(GdipImageCodecInfo_t2577501090 ), 0, 0 };";
    map<string, string> result = parseIl2CppTypeDefinitionSizes(code);

    cout << "Name: " << result["name"] << endl;
    cout << "Size: " << result["size"] << endl;
    cout << "Type: " << result["type"] << endl;

    return 0;
}
