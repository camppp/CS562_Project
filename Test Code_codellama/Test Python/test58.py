import logging

class CmdStep:
    def __init__(self, name, context):
        self.name = name
        self.context = context

    def run_step(self, is_shell):
        logger = logging.getLogger(__name__)
        logger.debug(f"Starting command step {self.name}")
        # Simulate the execution of the command step
        # ...
        logger.debug(f"Completed command step {self.name}")

# Create a command step
step = CmdStep("echo 'Hello, world!'", {})

# Run the command step
step.run_step(is_shell=False)