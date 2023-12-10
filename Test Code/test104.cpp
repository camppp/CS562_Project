python
class StateMachine:
    def __init__(self, initial_state):
        self.current_state = initial_state
        self.transitions = {}

    def add_transition(self, from_state, to_state, condition):
        if from_state not in self.transitions:
            self.transitions[from_state] = []
        self.transitions[from_state].append((to_state, condition))

    def is_valid_transition(self, from_state, to_state):
        if from_state in self.transitions:
            for transition in self.transitions[from_state]:
                if transition[0] == to_state and transition[1]():
                    return True
        return False

    def get_current_state(self):
        return self.current_state

# Example usage
def condition_true():
    return True

def condition_false():
    return False

sm = StateMachine('state1')
sm.add_transition('state1', 'state2', condition_true)
sm.add_transition('state2', 'state3', condition_true)
sm.add_transition('state2', 'state4', condition_false)

print(sm.is_valid_transition('state1', 'state2'))  # Output: True
print(sm.is_valid_transition('state2', 'state3'))  # Output: True
print(sm.is_valid_transition('state2', 'state4'))  # Output: False
print(sm.get_current_state())  # Output: state1
