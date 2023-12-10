python
class Robot:
    def __init__(self):
        self.x = 0
        self.y = 0

    def move(self, direction: str, distance: int):
        if direction == "up":
            self.y += distance
        elif direction == "down":
            self.y -= distance
        elif direction == "left":
            self.x -= distance
        elif direction == "right":
            self.x += distance

    def process_request(self, request_type: str):
        print(f"Processing request: {request_type}")

# Sample usage
robot = Robot()
robot.move("up", 5)
robot.move("right", 3)
robot.process_request("pickup")
robot.move("down", 2)
robot.process_request("dropoff")
