def find_palindromes(words):
    palindromes = [word for word in words if word.lower() == word[::-1].lower()]
    return palindromes