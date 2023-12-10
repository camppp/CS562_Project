python
class WeaponAI:
    def __init__(self):
        self.Firing = False
        self.Charged = False
        self.EnemyID = None
        self.EffectID = None

    def process_commands(self, Commands, WeaponObj):
        Commands.Set_Player_Type(WeaponObj, 0)  # Set the player type for the weapon object
        Commands.Enable_Enemy_Seen(WeaponObj, True)  # Enable enemy detection for the weapon object
        Commands.Enable_Hibernation(WeaponObj, False)  # Disable hibernation for the weapon object
        Commands.Innate_Enable(WeaponObj)  # Enable the innate ability for the weapon object

        # Initialize variables
        self.Firing = False
        self.Charged = False
        self.EnemyID = None
        self.EffectID = None
