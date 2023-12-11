enum class Types {
    VoidStar,
    Void,
    Bool
};

Types parseType(std::string& text) {
    if (text.substr(0, 5) == "void*") {
        CLD_ASSERT(!result);
        result = Types::VoidStar;
        text.remove_prefix(5);
    } else if (text.substr(0, 4) == "void") {
        CLD_ASSERT(!result);
        result = Types::Void;
        text.remove_prefix(4);
    } else if (text.substr(0, 4) == "bool") {
        CLD_ASSERT(!result);
        result = Types::Bool;
        text.remove_prefix(4);
    } else {
        // Handle the case when the input text does not match any of the specified type prefixes
        CLD_ASSERT(!result);
        result = Types::Void;
        text.remove_prefix(4);
    }
    return result;
}
