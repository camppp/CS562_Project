int minAttacksToDefeat(int hp, int dmg, int num_attacks) {
    if (dmg >= hp) {
        return 1; // If the damage is greater than or equal to the monster's health, it can be defeated in one attack
    } else if (dmg * num_attacks < hp) {
        return -1; // If the total damage from all attacks is less than the monster's health, it cannot be defeated in a single turn
    } else {
        int remaining_hp = hp;
        int attacks_required = 0;
        while (remaining_hp > 0) {
            remaining_hp -= dmg;
            attacks_required++;
        }
        return attacks_required;
    }
}
