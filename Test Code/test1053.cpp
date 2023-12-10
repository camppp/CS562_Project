python
from typing import List, Tuple

def countDistinctStates(states: List[Tuple[int, int]]) -> int:
    distinct_states = set()  # Use a set to store distinct states
    for state in states:
        distinct_states.add(state)  # Add each state to the set
    return len(distinct_states)  # Return the count of distinct states
