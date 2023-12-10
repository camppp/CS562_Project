python
class EventSubscriptionManager:
    def __init__(self):
        self.subscriptions = {}  # Dictionary to store event subscriptions

    def handle_subscription_request(self, request_type, subscription_id, component_id):
        if request_type == "new":
            self.subscriptions[subscription_id] = component_id
        elif request_type == "update":
            if subscription_id in self.subscriptions:
                self.subscriptions[subscription_id] = component_id
            else:
                print("Subscription ID not found for update")
        elif request_type == "delete":
            if subscription_id in self.subscriptions:
                del self.subscriptions[subscription_id]
            else:
                print("Subscription ID not found for deletion")

    def forward_event(self, event, subscription_id):
        if subscription_id in self.subscriptions:
            component_id = self.subscriptions[subscription_id]
            # Forward the event to the component with the given subscription ID
            print(f"Forwarding event '{event}' to component '{component_id}'")
        else:
            print("Subscription ID not found for event forwarding")

# Example usage
manager = EventSubscriptionManager()
manager.handle_subscription_request("new", "sub1", "component1")
manager.handle_subscription_request("new", "sub2", "component2")
manager.handle_subscription_request("update", "sub1", "component3")
manager.forward_event("Event1", "sub1")
manager.forward_event("Event2", "sub2")
manager.handle_subscription_request("delete", "sub1", "")
manager.forward_event("Event3", "sub1")
