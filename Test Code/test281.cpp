python
def isBalancedBraces(code: str) -> bool:
    stack = []
    in_comment = False

    for char in code:
        if char == '/' and not in_comment and len(stack) > 0 and stack[-1] == '{':
            in_comment = True
        elif char == '\n' and in_comment:
            in_comment = False
        elif not in_comment:
            if char == '{':
                stack.append('{')
            elif char == '}':
                if len(stack) == 0 or stack[-1] != '{':
                    return False
                stack.pop()

    return len(stack) == 0
