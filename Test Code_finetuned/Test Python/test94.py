class RobotController:
    STATE_IDLE = "IDLE"

    def __init__(self, name: str):
        self.name = name
        self.battery = 100
        self.state = self.STATE_IDLE
        self.available = True

    def set_state(self, new_state: str):
        self.state = new_state

    def charge_battery(self, amount: int):
        self.battery += amount

    def toggle_availability(self):
        self.available = not self.available

    def get_name(self) -> str:
        return self.name

    def get_battery_level(self) -> int:
        return self.battery

    def get_state(self) -> str:
        return self.state

    def is_available(self) -> bool:
        return self.available