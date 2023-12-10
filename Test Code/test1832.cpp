python
import re
from collections import Counter

def analyze_word_frequency(file_path, N):
    # Read the text file
    with open(file_path, 'r') as file:
        text = file.read().lower()  # Convert text to lowercase

    # Tokenize the text into words
    words = re.findall(r'\b\w+\b', text)

    # Exclude stop words
    stop_words = set([
        "the", "and", "of", "to", "in", "a", "is", "it", "that", "as", "was", "for", "on", "with", "by", "at", "but",
        "from", "or", "an", "are", "not", "this", "be", "which", "have", "has", "had", "one", "we", "all", "their",
        "there", "when", "who", "where", "why", "what", "how", "so", "if", "my", "your", "his", "her", "its", "our",
        "their", "some", "more", "most", "many", "much", "few", "little", "other", "only", "own", "same", "such",
        "no", "nor", "not", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"
    ])
    words = [word for word in words if word not in stop_words]

    # Count the frequency of words
    word_counts = Counter(words)

    # Output the top N most frequently occurring words
    top_words = word_counts.most_common(N)
    for word, count in top_words:
        print(f"{word}: {count}")
