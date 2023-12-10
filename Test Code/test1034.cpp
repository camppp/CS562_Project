python
class Room:
    def __init__(self, name, description):
        self.name = name
        self.description = description
        self.exits = {}
        self.items = []

    def add_exit(self, direction, room):
        self.exits[direction] = room

    def remove_exit(self, direction):
        if direction in self.exits:
            del self.exits[direction]

    def add_item(self, item):
        self.items.append(item)

    def remove_item(self, item):
        if item in self.items:
            self.items.remove(item)


class Player:
    def __init__(self, current_room):
        self.current_room = current_room
        self.inventory = []

    def move(self, direction):
        if direction in self.current_room.exits:
            self.current_room = self.current_room.exits[direction]
            print("You have moved to", self.current_room.name)
        else:
            print("There is no exit in that direction.")

    def pick_up_item(self, item):
        if item in self.current_room.items:
            self.inventory.append(item)
            self.current_room.remove_item(item)
            print("You have picked up", item)
        else:
            print("There is no such item in this room.")

    def drop_item(self, item):
        if item in self.inventory:
            self.inventory.remove(item)
            self.current_room.add_item(item)
            print("You have dropped", item)
        else:
            print("You don't have that item in your inventory.")
