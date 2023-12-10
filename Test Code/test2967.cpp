python
import re

def countComments(shaderSource: str) -> int:
    in_string_literal = False
    in_comment = False
    comment_count = 0

    for i in range(len(shaderSource)):
        if shaderSource[i] == '"' and (i == 0 or shaderSource[i-1] != '\\'):
            in_string_literal = not in_string_literal
        elif not in_string_literal:
            if shaderSource[i:i+2] == '/*' and not in_comment:
                in_comment = True
                comment_count += 1
            elif shaderSource[i:i+2] == '*/' and in_comment:
                in_comment = False
            elif shaderSource[i:i+2] == '//' and not in_comment:
                comment_count += 1
                break

    return comment_count
