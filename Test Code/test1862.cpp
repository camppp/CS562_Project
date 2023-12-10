python
class ShaderProgram:
    def __init__(self):
        self.attribute_bindings = {}

    def BindAttrib(self, index, name):
        if index in self.attribute_bindings.values():
            raise ValueError(f"Attribute index {index} is already bound to another attribute")

        if name in self.attribute_bindings:
            raise ValueError(f"Attribute name '{name}' is already bound to index {self.attribute_bindings[name]}")

        self.attribute_bindings[name] = index
