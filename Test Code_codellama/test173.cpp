class ShadowedBorderTextureMaterial : public ShadowedBorderRectangleMaterial {
public:
    QSGMaterialType* type() const override {
        return &staticType;
    }

    int compare(const QSGMaterial *other) const override {
        auto material = static_cast<const ShadowedBorderTextureMaterial *>(other);

        auto result = ShadowedBorderRectangleMaterial::compare(other);
        if (result != 0) {
            return result;
        }

        // Compare additional properties of ShadowedBorderTextureMaterial
        if (this->texture() != material->texture()) {
            return this->texture() < material->texture() ? -1 : 1;
        }

        if (this->borderWidth() != material->borderWidth()) {
            return this->borderWidth() < material->borderWidth() ? -1 : 1;
        }

        if (this->borderColor() != material->borderColor()) {
            return this->borderColor() < material->borderColor() ? -1 : 1;
        }

        return 0;
    }

private:
    static QSGMaterialType staticType;
};
