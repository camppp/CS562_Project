python
from typing import List, Union

class ProofState:
    def __init__(self, hypotheses: List[str], substitution: dict):
        self.hypotheses = hypotheses
        self.substitution = substitution

class Goal:
    def __init__(self, statement: str):
        self.statement = statement

def revertTactic(s: ProofState, goals: List[Goal], n: str) -> Union[ProofState, str]:
    if n in s.hypotheses:
        new_subst = {}  # Create a new substitution
        for key, value in s.substitution.items():
            new_subst[key] = applyNewMeta(value)  # Apply a new metavariable to the substitution

        new_goals = goals[1:]  # Update the list of goals by removing the first goal
        new_proof_state = ProofState(s.hypotheses.remove(n), new_subst)  # Create a new proof state with the reverted hypothesis and updated substitution

        return new_proof_state
    else:
        return "invalid 'revert' tactic, unknown hypothesis '" + n + "'"
