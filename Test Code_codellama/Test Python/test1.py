def parse_tokens(tokens):
    parsed_tokens = []
    for token in tokens:
        if token[0] == 'daddress':
            parsed_tokens.append(daddress(token))
        elif token[0] == 'dcommand':
            parsed_tokens.append(dcommand(token))
        elif token[0] == 'doaddress':
            parsed_tokens.append(doaddress(token))
        elif token[0] == 'dosymbol':
            parsed_tokens.append(dosymbol(token))
    return parsed_tokens