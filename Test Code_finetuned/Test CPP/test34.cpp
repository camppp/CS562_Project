class Token:
    IDENTIFIER = 0
    PARENTHESES_O = 1
    # other token types

def expression():
    # Assume this function is implemented elsewhere
    pass

def parseSelectionStatement(tokens):
    if tokens[0].type!= Token.IDENTIFIER or tokens[1].type!= Token.PARENTHESES_O:
        raise ValueError("Invalid selection statement")

    # Create a new If node
    if_node = If()

    # Parse the expression within the selection statement
    if_node.condition = expression(tokens[2:])

    return if_node