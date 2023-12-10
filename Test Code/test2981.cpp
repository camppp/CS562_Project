python
from typing import List

def redasm_interpreter(instructions: List[str]) -> int:
    stack = []
    for instruction in instructions:
        if instruction.startswith("PUSH"):
            value = int(instruction.split()[1])
            stack.append(value)
        elif instruction == "POP":
            if stack:
                stack.pop()
            else:
                return -1  # Error: popping from an empty stack
        elif instruction == "ADD":
            if len(stack) >= 2:
                stack.append(stack.pop() + stack.pop())
            else:
                return -1  # Error: insufficient operands for addition
        elif instruction == "SUB":
            if len(stack) >= 2:
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            else:
                return -1  # Error: insufficient operands for subtraction
        elif instruction == "MUL":
            if len(stack) >= 2:
                stack.append(stack.pop() * stack.pop())
            else:
                return -1  # Error: insufficient operands for multiplication
        elif instruction == "DIV":
            if len(stack) >= 2:
                divisor = stack.pop()
                if divisor == 0:
                    return -1  # Error: division by zero
                dividend = stack.pop()
                stack.append(dividend // divisor)
            else:
                return -1  # Error: insufficient operands for division
    return stack[-1] if stack else 0  # Return the top element of the stack or 0 if the stack is empty
