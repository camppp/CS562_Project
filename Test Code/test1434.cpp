python
from typing import List, Dict

def categorize_licenses(licenses: List[str]) -> Dict[str, List[str]]:
    categorized_licenses = {"BSD": [], "MIT": [], "Other": []}

    for license in licenses:
        if license.startswith("BSD"):
            categorized_licenses["BSD"].append(license)
        elif license.startswith("MIT"):
            categorized_licenses["MIT"].append(license)
        else:
            categorized_licenses["Other"].append(license)

    return categorized_licenses
