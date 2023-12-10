// IEntity destructor implementation
IEntity::~IEntity()
{
    // Add any necessary cleanup code here
}

// Implementation of hasEmission() in the IEntity class
bool IEntity::hasEmission() const
{
    // Add logic to determine if the entity has emission
    return false; // Replace with actual logic
}

// Implementation of isCollidable() in the IEntity class
bool IEntity::isCollidable() const
{
    // Add logic to determine if the entity is collidable
    return true; // Replace with actual logic
}

// Ensure proper inheritance and dumpInformation() implementation in the IEntity class
std::string IEntity::dumpInformation() const
{
    std::stringstream stream;
    stream << ITransformable::dumpInformation()
           << "  <IEntity>: " << std::endl
           << "    HasEmission:      " << (hasEmission() ? "true" : "false") << std::endl
           << "    IsCollidable:     " << (isCollidable() ? "true" : "false") << std::endl;
    // Add any additional information specific to IEntity
    return stream.str();
}
