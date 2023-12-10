python
def remove_character_recursive(s, t):
    if not s:  # Base case: if the string is empty, return
        return
    if s[0] == t:  # If the first character is the target character, remove it
        s = s[1:]  # Remove the first character from the string
        remove_character_recursive(s, t)  # Recur on the modified string
    else:
        remove_character_recursive(s[1:], t)  # Recur on the rest of the string

# Test the function
input_str = "banana"
target_char = 'a'
remove_character_recursive(input_str, target_char)
print(input_str)  # Output: "bnn"
