python
def reverseString(str):
    reversed_str = ""
    for i in range(len(str) - 1, -1, -1):
        reversed_str += str[i]
    return reversed_str
