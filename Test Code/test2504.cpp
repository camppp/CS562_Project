python
class EventHandler:
    def __init__(self):
        self.event_handlers = {}

    def registerHandler(self, eventType, handlerFunction):
        if eventType in self.event_handlers:
            self.event_handlers[eventType].append(handlerFunction)
        else:
            self.event_handlers[eventType] = [handlerFunction]

    def handleEvent(self, eventType):
        if eventType in self.event_handlers:
            for handler in self.event_handlers[eventType]:
                if handler(eventType):  # Assuming the handler returns True if the event is handled
                    return True
        return False
