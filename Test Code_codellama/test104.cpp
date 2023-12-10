class StateMachine:
    def __init__(self, initial_state):
        self.current_state = initial_state
        self.transitions = {}

    def add_transition(self, from_state, to_state, condition):
        self.transitions[(from_state, to_state)] = condition

    def is_valid_transition(self, from_state, to_state):
        return self.transitions.get((from_state, to_state), False)

    def get_current_state(self):
        return self.current_state
