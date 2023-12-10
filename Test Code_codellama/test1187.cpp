def countStates(states: List[stt]) -> Tuple[int, int]:
    endline_count = 0
    other_count = 0
    for state in states:
        if state == s_endline:
            endline_count += 1
        elif state == s_other:
            other_count += 1
    return (endline_count, other_count)
