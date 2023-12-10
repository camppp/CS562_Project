python
from typing import List, Tuple
import re

def replaceMacros(code: str, macros: List[Tuple[str, str]]) -> str:
    for macro, value in macros:
        code = re.sub(r'\b' + re.escape(macro) + r'\b', value, code)
    return code
