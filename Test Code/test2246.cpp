python
class StatusTracker:
    def __init__(self):
        self.current_status = 1  # Default status is kStatusIdx

    def set_status(self, status):
        if status in [1, 2, 3]:
            self.current_status = status
        else:
            raise ValueError("Invalid status value")

    def get_status(self):
        return self.current_status

    def is_in_status(self, status):
        return self.current_status == status

    def reset_status(self):
        self.current_status = 1  # Reset to default status kStatusIdx


# Demonstration
tracker = StatusTracker()
print(tracker.get_status())  # Output: 1 (default status kStatusIdx)

tracker.set_status(2)
print(tracker.get_status())  # Output: 2

print(tracker.is_in_status(2))  # Output: True
print(tracker.is_in_status(3))  # Output: False

tracker.reset_status()
print(tracker.get_status())  # Output: 1 (default status kStatusIdx)
