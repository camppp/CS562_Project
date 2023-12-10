python
import re

def extractCopyrightYear(copyrightText: str) -> str:
    pattern = r'Copyright \(c\) (\d{4}(?:-\d{4})?)'
    match = re.search(pattern, copyrightText)
    if match:
        return match.group(1)
    else:
        return "Year not found"
