python
class CallStack:
    def __init__(self):
        self.stack = []

    def pushStack(self, frameSize, argumentCount, function, destination, instructions):
        frame = {
            "frameSize": frameSize,
            "argumentCount": argumentCount,
            "function": function,
            "destination": destination,
            "instructions": instructions
        }
        self.stack.append(frame)

    def popStack(self):
        if self.stack:
            self.stack.pop()

    def runFunctionPointerBlock(self, thread):
        if self.stack:
            frame = self.stack[-1]
            # Execute function pointer block using frame instructions
            # Pass any required parameters from the frame
            # Implement the execution logic here
        else:
            raise Exception("Call stack is empty, cannot run function pointer block")
