def daddress(t):
    return ('daddress', t[1])

def dcommand(t):
    return ('dcommand', t[1])

def doaddress(t):
    return ('doaddress', t[1])

def dosymbol(t):
    return ('dosymbol', t[1])

tokens = [('daddress', '123'), ('dcommand', 'print'), ('dosymbol', 'x')]
print(parse_tokens(tokens))