bool canWeaponTargetUnit(u8 weaponId, const CUnit *target, const CUnit *attacker) {
  if (weaponId >= WEAPON_TYPE_COUNT) {
    // Assuming the game's rules are defined elsewhere, implement the logic to check if the weapon can target the specified unit
    switch (weaponId) {
      case 0:  // Example rule for weapon ID 0
        // Check if the target unit is within range and meets other conditions for this weapon
        // Implement the specific logic for weapon ID 0
        return /* true or false based on the game's rules */;
      case 1:  // Example rule for weapon ID 1
        // Check if the target unit is visible and meets other conditions for this weapon
        // Implement the specific logic for weapon ID 1
        return /* true or false based on the game's rules */;
      // Add cases for other weapon IDs with their specific targeting rules
      default:
        // Handle any default case or return false if the weapon ID is not recognized
        return false;
    }
  }
  return false;  // Default return value if the weapon ID is invalid
}
