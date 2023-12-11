from bs4 import BeautifulSoup
from collections import Counter
import re

def analyze_html(file_path, N):
    with open(file_path, 'r') as file:
        html_content = file.read()

    soup = BeautifulSoup(html_content, 'html.parser')
    text = soup.get_text()

    words = re.findall(r'\b\w+\b', text.lower())
    word_counts = Counter(words)

    top_N_words = word_counts.most_common(N)

    output = ', '.join([f'{word}: {count}' for word, count in top_N_words])

    return output

print(analyze_html('sample.html', 3))