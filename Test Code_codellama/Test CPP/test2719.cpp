class Instance {
public:
    Instance(MeshId meshId) : meshId_(meshId) {}

    bool isStatic() const {
        return isStatic_;
    }

    void setStatic(bool b) {
        isStatic_ = b;
    }

    MeshId getMeshId() const {
        return meshId_;
    }

private:
    MeshId meshId_;
    bool isStatic_;
};
