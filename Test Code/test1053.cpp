def countDistinctStates(states: List[Tuple[int, int]]) -> int:
    distinct_states = set()
    for state in states:
        distinct_states.add(state)
    return len(distinct_states)
