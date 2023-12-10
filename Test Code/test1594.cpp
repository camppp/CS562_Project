bool validateBaseTexture(const std::map<std::string, Parameter>& params) {
    return params.find("BASETEXTURE") != params.end() && params["BASETEXTURE"].IsDefined();
}
