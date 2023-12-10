python
def countDistinctCharacters(s):
    char_count = {}
    for char in s:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1
    
    result = []
    for char, count in char_count.items():
        result.append(f"{char} {count}")
    
    return result
