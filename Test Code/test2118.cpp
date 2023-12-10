void processCommands(Commands& commands, Weapon& weapon) {
    // Set the player type
    commands.setPlayerType(weapon.getPlayerType());

    // Enable enemy detection
    commands.enableEnemyDetection(weapon.getEnemyDetection());

    // Enable hibernation
    commands.enableHibernation(weapon.getHibernation());

    // Enable innate ability
    commands.enableInnateAbility(weapon.getInnateAbility());

    // Initialize variables
    Firing = false;
    Charged = false;
    EnemyID = -1;
    EffectID = -1;
}
