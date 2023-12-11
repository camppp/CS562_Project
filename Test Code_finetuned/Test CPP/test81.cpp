import collections
import re
import nltk
from nltk.corpus import stopwords

nltk.download('stopwords')

def analyze_text(file_name, n):
    with open(file_name, 'r') as file:
        text = file.read().lower()

    words = re.findall(r'\b\w+\b', text)
    stop_words = set(stopwords.words('english'))

    filtered_words = [word for word in words if word not in stop_words]

    word_counts = collections.Counter(filtered_words)

    top_n_words = word_counts.most_common(n)

    for word, count in top_n_words:
        print(f"{word}: {count}")

analyze_text("input.txt", 3)


pip install nltk