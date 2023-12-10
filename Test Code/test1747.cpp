python
class RadioChannel:
    def __init__(self, name, frequency):
        self.name = name
        self.frequency = frequency

class RadioManager:
    def __init__(self):
        self.channels = []

    def add_channel(self, name, frequency):
        # Add a new channel with the given name and frequency
        # If the name is not unique, do not add the channel
        if not any(channel.name == name for channel in self.channels):
            self.channels.append(RadioChannel(name, frequency))

    def remove_channel(self, name):
        # Remove the channel with the given name
        # If the channel does not exist, do nothing
        self.channels = [channel for channel in self.channels if channel.name != name]

    def switch_to_next_channel(self):
        # Switch to the next available channel in the list
        # If there are no channels, do nothing
        if self.channels:
            current_index = 0
            for i, channel in enumerate(self.channels):
                if channel.name == self.current_channel.name:
                    current_index = i
                    break
            next_index = (current_index + 1) % len(self.channels)
            self.current_channel = self.channels[next_index]

# Example usage
radio_manager = RadioManager()
radio_manager.add_channel("Rock", 98.5)
radio_manager.add_channel("Pop", 102.7)
radio_manager.switch_to_next_channel()
radio_manager.remove_channel("Rock")
