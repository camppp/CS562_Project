class RadioManager:
    def __init__(self):
        self.channels = []

    def add_channel(self, name, frequency):
        if name in self.channels:
            return
        self.channels.append(RadioChannel(name, frequency))

    def remove_channel(self, name):
        if name not in self.channels:
            return
        self.channels.remove(name)

    def switch_to_next_channel(self):
        if not self.channels:
            return
        self.current_channel = self.channels[0]
        self.channels.remove(self.current_channel)

    def get_current_channel(self):
        return self.current_channel
