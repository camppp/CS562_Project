python
import re

def extractCopyright(sourceCode):
    # Regular expression to match copyright notice in different comment styles
    pattern = r'(?://|/\*|<!--)\s*Copyright\s*\(.*?\)\s*.*?(?://|/\*|-->|\n\n)'
    
    # Find all matches of the pattern in the source code
    matches = re.findall(pattern, sourceCode, re.DOTALL)
    
    # Extract the copyright notice from the matches
    if matches:
        # Remove comment delimiters and leading/trailing whitespace
        copyright = re.sub(r'(?://|/\*|<!--)\s*|\s*(?://|/\*|-->|\n\n)', '', matches[0])
        return copyright.strip()
    else:
        return "Copyright notice not found"
