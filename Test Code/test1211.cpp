python
class ContextMenu:
    def __init__(self):
        self.items = []

    def addItem(self, item):
        self.items.append(item)

    def show(self):
        for index, item in enumerate(self.items, start=1):
            print(f"{index}. {item}")
        selected_index = int(input("Enter the number of the item to select: "))
        if 1 <= selected_index <= len(self.items):
            self.handleSelection(self.items[selected_index - 1])
        else:
            print("Invalid selection")

    def handleSelection(self, item):
        print(f"Selected: {item}")

# Example usage
menu = ContextMenu()
menu.addItem("Copy")
menu.addItem("Paste")
menu.addItem("Cut")
menu.show()
