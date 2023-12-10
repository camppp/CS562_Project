python
class GadgetFactory:
    def __init__(self):
        self.registered_gadgets = {}

    def register_gadget(self, gadget_name, gadget_class):
        self.registered_gadgets[gadget_name] = gadget_class

    def create_gadget(self, gadget_name, *args, **kwargs):
        if gadget_name in self.registered_gadgets:
            gadget_class = self.registered_gadgets[gadget_name]
            return gadget_class(*args, **kwargs)
        else:
            raise ValueError(f"Gadget '{gadget_name}' is not registered.")

    def get_registered_gadgets(self):
        return list(self.registered_gadgets.keys())


class CoilComputationGadget:
    def __init__(self, *args, **kwargs):
        # Initialization logic for CoilComputationGadget
        pass


# Example usage
factory = GadgetFactory()
factory.register_gadget("CoilComputationGadget", CoilComputationGadget)
gadget = factory.create_gadget("CoilComputationGadget")
print(gadget)
print(factory.get_registered_gadgets())
