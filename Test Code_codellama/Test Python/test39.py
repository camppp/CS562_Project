class LightSwitch:
    def __init__(self):
        self.is_enabled = False
        self.on_count = 0
        self.off_count = 0

    def turn_on(self):
        if not self.is_enabled:
            self.is_enabled = True
            self.on_count += 1

    def turn_off(self):
        if self.is_enabled:
            self.is_enabled = False
            self.off_count += 1

    def get_state(self):
        return self.is_enabled

    def reset_count(self):
        self.on_count = 0
        self.off_count = 0