python
from typing import List

def remove_phonies(strings: List[str]) -> List[str]:
    return [s for s in strings if "phony" not in s.lower()]
