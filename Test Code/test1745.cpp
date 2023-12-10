python
class Mouse:
    def __init__(self, scroll_y, down_buttons):
        self.scroll_y = scroll_y
        self.down_buttons = down_buttons

    def GetScrollY(self):
        return self.scroll_y

    def GetDownButtons(self):
        return self.down_buttons

# Scenario
# Instantiate a Mouse object with scroll position and pressed buttons
mouse = Mouse(20, ["left", "right"])

# Retrieve the scroll position and pressed buttons
scroll_position = mouse.GetScrollY()
pressed_buttons = mouse.GetDownButtons()

# Output the retrieved information
print("Scroll Position:", scroll_position)
print("Pressed Buttons:", pressed_buttons)
