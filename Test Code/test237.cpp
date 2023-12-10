python
def decryptMessage(message, offset):
    decrypted = ""
    for char in message:
        decrypted_char = chr(((ord(char) - 32 - offset) % 95) + 32)
        decrypted += decrypted_char
    return decrypted

# Test the function
encrypted_message = "Khoor#Zruog"
offset_value = 3
decrypted_result = decryptMessage(encrypted_message, offset_value)
print(decrypted_result)  # Output: "Hello World"
