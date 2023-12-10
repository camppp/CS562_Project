python
from typing import List

def extractParts(parts: List[str]) -> List[str]:
    if len(parts) == WAC_CERTIFY_MANDATORY_PART_HIGH_COUNT:
        return parts[:WAC_CERTIFY_MANDATORY_PART_MICRO_INDEX + 1]
    else:
        return []
