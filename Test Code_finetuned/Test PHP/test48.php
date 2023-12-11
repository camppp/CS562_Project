class Competition:
    def __init__(self):
        self.participants = {}

    def add_participant(self, identifier, info):
        if identifier in self.participants:
            print("Participant with this identifier already exists.")
        else:
            self.participants[identifier] = info
            print("Participant added successfully.")

    def get_participant(self, identifier):
        if identifier in self.participants:
            return self.participants[identifier]
        else:
            return "Participant not found."

# Usage
competition = Competition()
competition.add_participant("123", {"name": "John", "age": 20})
print(competition.get_participant("123"))  # Output: {'name': 'John', 'age': 20}