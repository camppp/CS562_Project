python
from enum import Enum
from typing import List, Tuple

class stt(Enum):
    s_start = 1
    s_process = 2
    s_endline = 3
    s_other = 4

def countStates(states: List[stt]) -> Tuple[int, int]:
    endline_count = 0
    other_count = 0
    for state in states:
        if state == stt.s_endline:
            endline_count += 1
        elif state == stt.s_other:
            other_count += 1
    return (endline_count, other_count)

# Test the function with the given example
input_states = [stt.s_start, stt.s_process, stt.s_endline, stt.s_other, stt.s_endline, stt.s_start, stt.s_other, stt.s_endline]
print(countStates(input_states))  # Output: (3, 2)
