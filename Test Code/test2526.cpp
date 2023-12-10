python
def evaluateExpression(expression):
    def apply_operator(operands, operator):
        b, a = operands.pop(), operands.pop()
        if operator == '+':
            operands.append(a + b)
        elif operator == '-':
            operands.append(a - b)
        elif operator == '*':
            operands.append(a * b)
        elif operator == '/':
            operands.append(a / b)

    precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
    operators = []
    operands = []
    i = 0
    while i < len(expression):
        if expression[i].isdigit():
            j = i
            while j < len(expression) and (expression[j].isdigit() or expression[j] == '.'):
                j += 1
            operands.append(float(expression[i:j]))
            i = j
        elif expression[i] in precedence:
            while operators and precedence[operators[-1]] >= precedence[expression[i]]:
                apply_operator(operands, operators.pop())
            operators.append(expression[i])
            i += 1
        elif expression[i] == '(':
            operators.append(expression[i])
            i += 1
        elif expression[i] == ')':
            while operators[-1] != '(':
                apply_operator(operands, operators.pop())
            operators.pop()
            i += 1
        else:
            i += 1
    while operators:
        apply_operator(operands, operators.pop())
    return operands[0]
