#include <string>

enum class Types
{
    VoidStar,
    Void,
    Bool
};

Types parseType(std::string& text)
{
    Types result;

    if (text.substr(0, 5) == "void*")
    {
        result = Types::VoidStar;
        text.erase(0, 5);
    }
    else if (text.substr(0, 4) == "void")
    {
        result = Types::Void;
        text.erase(0, 4);
    }
    else if (text.substr(0, 4) == "bool")
    {
        result = Types::Bool;
        text.erase(0, 4);
    }

    return result;
}
