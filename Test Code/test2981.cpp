def redasm_interpreter(instructions: List[str]) -> int:
    stack = []
    for instruction in instructions:
        if instruction == "PUSH":
            stack.append(int(instruction[5:]))
        elif instruction == "POP":
            if len(stack) == 0:
                return -1
            stack.pop()
        elif instruction == "ADD":
            if len(stack) < 2:
                return -1
            stack.append(stack.pop() + stack.pop())
        elif instruction == "SUB":
            if len(stack) < 2:
                return -1
            stack.append(stack.pop() - stack.pop())
        elif instruction == "MUL":
            if len(stack) < 2:
                return -1
            stack.append(stack.pop() * stack.pop())
        elif instruction == "DIV":
            if len(stack) < 2:
                return -1
            if stack.pop() == 0:
                return -1
            stack.append(stack.pop() // stack.pop())
    return stack.pop()
