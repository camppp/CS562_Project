bool Mud::remItem(Item* item) {
    // Check if the item is a corpse
    if (item->getType() == ModelType::Corpse) {
        // Remove the corpse from the game world
        std::cout << "Removing corpse " << item->getName() << " from the game world." << std::endl;
        return true;
    }

    // Check if the item is a weapon
    if (item->getType() == ModelType::Weapon) {
        // Remove the weapon from the game world
        std::cout << "Removing weapon " << item->getName() << " from the game world." << std::endl;
        return true;
    }

    // Check if the item is armor
    if (item->getType() == ModelType::Armor) {
        // Remove the armor from the game world
        std::cout << "Removing armor " << item->getName() << " from the game world." << std::endl;
        return true;
    }

    // Check if the item is a potion
    if (item->getType() == ModelType::Potion) {
        // Remove the potion from the game world
        std::cout << "Removing potion " << item->getName() << " from the game world." << std::endl;
        return true;
    }

    // If the item is not a corpse, weapon, armor, or potion, return false
    return false;
}
