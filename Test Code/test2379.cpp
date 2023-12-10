python
def decodeString(s: str) -> str:
    stack = []
    current_num = 0
    current_str = ''
    
    for char in s:
        if char.isdigit():
            current_num = current_num * 10 + int(char)
        elif char == '[':
            stack.append(current_str)
            stack.append(current_num)
            current_str = ''
            current_num = 0
        elif char == ']':
            num = stack.pop()
            prev_str = stack.pop()
            current_str = prev_str + num * current_str
        else:
            current_str += char
    
    return current_str
