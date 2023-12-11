import time

class RembThrottler:
    def __init__(self, sender, clock):
        self.sender = sender
        self.clock = clock
        self.alpha = 0.5  # Smoothing factor
        self.last_feedback = None
        self.last_time = None
        self.last_rate = None

    def receive_feedback(self, feedback):
        self.last_feedback = feedback

    def calculate_rate(self):
        if self.last_feedback is None or self.last_time is None:
            return None

        elapsed_time = self.clock.time() - self.last_time
        if elapsed_time == 0:
            return self.last_rate

        rate = self.last_feedback / elapsed_time
        if self.last_rate is None:
            self.last_rate = rate
        else:
            self.last_rate = self.alpha * rate + (1 - self.alpha) * self.last_rate

        self.last_time = self.clock.time()
        return self.last_rate

    def send_data(self, data):
        rate = self.calculate_rate()
        if rate is not None:
            self.sender.send(data, rate)