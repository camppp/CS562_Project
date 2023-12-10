bool Knight::attack(Unit& target) {
    // Determine the outcome of the battle based on the knight's strength and the target's defense
    if (strength > target.defense) {
        // The knight wins the battle
        return true;
    } else {
        // The knight loses the battle
        return false;
    }
}
