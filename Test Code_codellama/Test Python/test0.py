def find_palindromes(words):
    # Your code here
    palindromes = []
    for word in words:
        if word == word[::-1]:
            palindromes.append(word)
    return palindromes