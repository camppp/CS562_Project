python
from typing import List
import re

def extractFunctionNames(sourceCode: str) -> List[str]:
    function_names = re.findall(r'\b\w+\s*\([^)]*\)\s*{', sourceCode)
    function_names = [name.split('(')[0].strip() for name in function_names]
    return function_names
