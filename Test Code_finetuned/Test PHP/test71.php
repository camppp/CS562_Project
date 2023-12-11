import re

def extractBraceContent(s):
    return re.findall(r'\{([^}]*)\}', s)

# Test the function
s = "Hello {W}orld! This is a {T}est {S}tring."
print(extractBraceContent(s))  # Output: ['W', 'T', 'S']