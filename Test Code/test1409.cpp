python
def format_text(input_text):
    stack = []
    formatted_text = ""
    i = 0
    while i < len(input_text):
        if input_text[i:i+3] == "<B>":
            stack.append("B")
            i += 3
        elif input_text[i:i+4] == "</B>":
            stack.pop()
            i += 4
        elif input_text[i:i+3] == "<I>":
            stack.append("I")
            i += 3
        elif input_text[i:i+4] == "</I>":
            stack.pop()
            i += 4
        elif input_text[i:i+3] == "<U>":
            stack.append("U")
            i += 3
        elif input_text[i:i+4] == "</U>":
            stack.pop()
            i += 4
        else:
            if not stack:
                formatted_text += input_text[i]
            i += 1
    return formatted_text
