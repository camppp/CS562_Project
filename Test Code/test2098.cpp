python
def count_word_occurrences(file_path, target_word):
    count = 0
    with open(file_path, 'r') as file:
        for line in file:
            count += line.split().count(target_word)
    return count

file_path = "sample.txt"
target_word = "sample"
occurrences = count_word_occurrences(file_path, target_word)
print(f"The word '{target_word}' occurs {occurrences} times in the file.")
