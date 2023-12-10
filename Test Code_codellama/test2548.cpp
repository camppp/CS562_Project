c
int minAttacksToDefeat(int hp, int dmg, int num_attacks) {
    int attacks = 0;
    int total_dmg = 0;
    while (total_dmg < hp && attacks < num_attacks) {
        total_dmg += dmg;
        attacks++;
    }
    if (total_dmg < hp) {
        return -1;
    }
    return attacks;
}
