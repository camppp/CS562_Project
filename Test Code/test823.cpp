python
def count_vowels(input_string):
    vowels = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0}
    for char in input_string:
        if char.lower() in vowels:
            vowels[char.lower()] += 1

    for vowel, count in vowels.items():
        print(f"{vowel.upper()}: {count}")

# Example usage
input_str = input("Enter a string: ")
count_vowels(input_str)
