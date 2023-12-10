python
class Room:
    def __init__(self, name, description, exits):
        self.name = name
        self.description = description
        self.exits = exits

    def get_name(self):
        return self.name

    def get_description(self):
        return self.description

    def get_exits(self):
        return self.exits

# Creating a sample room object
sample_room = Room("Lobby", "A spacious lobby with marble floors.", ["Hallway", "Courtyard"])

# Accessing attributes and methods of the sample room
print("Room Name:", sample_room.get_name())
print("Room Description:", sample_room.get_description())
print("Exits:", sample_room.get_exits())
