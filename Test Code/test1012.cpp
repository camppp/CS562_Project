python
class VariableNotAssignedError(Exception):
    pass

class VariableManager:
    def __init__(self):
        self.variables = {}

    def assign_variable(self, name, value):
        self.variables[name] = value

    def retrieve_variable(self, name):
        if name not in self.variables:
            raise VariableNotAssignedError(f"Variable '{name}' has not been assigned")
        return self.variables[name]

    def modify_variable(self, name, new_value):
        if name not in self.variables:
            raise VariableNotAssignedError(f"Variable '{name}' has not been assigned")
        self.variables[name] = new_value
