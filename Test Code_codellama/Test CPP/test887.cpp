class IEntity : public ITransformable {
public:
    virtual ~IEntity() {}
    virtual bool hasEmission() const { return false; }
    virtual bool isCollidable() const { return false; }
    virtual std::string dumpInformation() const {
        return ITransformable::dumpInformation() +
               "Entity information: " +
               "Has emission: " + std::to_string(hasEmission()) +
               "Is collidable: " + std::to_string(isCollidable());
    }
};
