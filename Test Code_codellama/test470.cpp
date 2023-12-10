def remove_character_recursive(s, t):
    if len(s) == 0:
        return
    if s[0] == t:
        s = s[1:]
    else:
        s = s[0] + remove_character_recursive(s[1:], t)
    return s
