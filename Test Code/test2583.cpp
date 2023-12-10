class Material {
private:
    ProgramTyp materialType;
    Color diffuseColor;
    Color specularColor;

public:
    Material(ProgramTyp type, Color diffuse, Color specular) : materialType(type), diffuseColor(diffuse), specularColor(specular) {}

    ~Material() {}

    void use() {
        useProg(materialType);
    }
};
