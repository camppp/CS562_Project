python
from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

def insert_word(root, word):
    node = root
    for char in word:
        if char not in node.children:
            node.children[char] = TrieNode()
        node = node.children[char]
    node.is_end_of_word = True

def find_concatenated_word(root, word, index, count):
    node = root
    for i in range(index, len(word)):
        char = word[i]
        if char not in node.children:
            return False
        node = node.children[char]
        if node.is_end_of_word:
            if i == len(word) - 1:
                return count >= 1
            if find_concatenated_word(root, word, i + 1, count + 1):
                return True
    return False

def longest_concatenated_word(words: List[str]) -> str:
    root = TrieNode()
    for word in words:
        insert_word(root, word)
    
    words.sort(key=lambda x: (-len(x), x))
    for word in words:
        if find_concatenated_word(root, word, 0, 0):
            return word
    return ""
