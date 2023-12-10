python
def count_phrase_occurrences(text_file, phrases_file):
    with open(text_file, 'r') as file:
        text = file.read()

    with open(phrases_file, 'r') as file:
        phrases = file.read().splitlines()

    phrase_counts = {}
    for phrase in phrases:
        count = text.count(phrase)
        phrase_counts[phrase] = count

    for phrase, count in phrase_counts.items():
        print(f"{phrase}: {count}")

# Usage
count_phrase_occurrences('license.txt', 'phrases.txt')
