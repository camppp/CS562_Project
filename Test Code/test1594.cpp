bool validateBaseTexture(const std::map<std::string, Parameter>& params) {
    auto it = params.find("BASETEXTURE");
    if (it != params.end()) {
        return it->second.IsDefined();
    }
    return false;
}
