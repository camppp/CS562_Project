enum class Type {
    None,
    Integer,
    Float,
    String,
    Boolean
};

Type Type::fromString(const std::string& str) {
    if (str == "None") {
        return Type::None;
    } else if (str == "Integer") {
        return Type::Integer;
    } else if (str == "Float") {
        return Type::Float;
    } else if (str == "String") {
        return Type::String;
    } else if (str == "Boolean") {
        return Type::Boolean;
    } else {
        return Type::None;
    }
}
