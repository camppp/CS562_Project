python
import re
from collections import Counter

def count_top_words(file_path, N):
    with open(file_path, 'r') as file:
        text = file.read().lower()
        words = re.findall(r'\w+', text)
        stop_words = set(['the', 'and', 'or', 'is', 'in', 'it', 'to', 'of', 'for', 'on', 'with', 'a', 'an'])
        filtered_words = [word for word in words if word not in stop_words]
        word_counts = Counter(filtered_words)
        top_words = word_counts.most_common(N)
        for word, count in top_words:
            print(f"{word}: {count}")

# Example usage
count_top_words('path_to_license_agreement.txt', 3)
