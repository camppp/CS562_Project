python
import re
from collections import Counter

# Read the license agreement from the file
with open('license.txt', 'r') as file:
    license_text = file.read()

# Define common stop words
stop_words = {'the', 'and', 'or', 'is', 'are', 'in', 'on', 'at', 'to', 'for', 'with', 'a', 'an', 'of', 'by', 'as', 'it', 'its', 'be', 'that', 'this', 'these', 'those', 'from', 'which', 'not', 'but', 'also', 'such', 'so', 'if', 'will', 'may', 'can', 'could', 'should', 'would', 'has', 'have', 'had', 'been', 'was', 'were', 'am', 'is', 'are', 'do', 'does', 'did', 'done', 'doing', 'will', 'shall', 'should', 'would', 'can', 'could', 'may', 'might', 'must', 'ought', 'need', 'dare', 'used', 'need', 'used', 'get', 'got', 'gotten', 'getting', 'let', 'lets', 'letting', 'like', 'likes', 'liked', 'liking', 'make', 'makes', 'made', 'making', 'see', 'sees', 'saw', 'seeing', 'say', 'says', 'said', 'saying', 'go', 'goes', 'went', 'going', 'take', 'takes', 'took', 'taking', 'come', 'comes', 'came', 'coming', 'keep', 'keeps', 'kept', 'keeping', 'help', 'helps', 'helped', 'helping', 'call', 'calls', 'called', 'calling', 'try', 'tries', 'tried', 'trying', 'put', 'puts', 'putting', 'mean', 'means', 'meant', 'meaning', 'let', 'lets', 'letting', 'begin', 'begins', 'began', 'beginning', 'start', 'starts', 'started', 'starting', 'show', 'shows', 'showed', 'showing', 'hear', 'hears', 'heard', 'hearing', 'play', 'plays', 'played', 'playing', 'run', 'runs', 'ran', 'running', 'move', 'moves', 'moved', 'moving', 'live', 'lives', 'lived', 'living', 'believe', 'believes', 'believed', 'believing', 'think', 'thinks', 'thought', 'thinking', 'know', 'knows', 'knew', 'knowing', 'want', 'wants', 'wanted', 'wanting', 'work', 'works', 'worked', 'working', 'use', 'uses', 'used', 'using', 'find', 'finds', 'found', 'finding', 'give', 'gives', 'gave', 'given', 'giving', 'tell', 'tells', 'told', 'telling', 'ask', 'asks', 'asked', 'asking', 'need', 'needs', 'needed', 'needing', 'feel', 'feels', 'felt', 'feeling', 'become', 'becomes', 'became', 'becoming', 'leave', 'leaves', 'left', 'leaving', 'put', 'puts', 'putting', 'mean', 'means', 'meant', 'meaning', 'let', 'lets', 'letting', 'begin', 'begins', 'began', 'beginning', 'start', 'starts', 'started', 'starting', 'show', 'shows', 'showed', 'showing', 'hear', 'hears', 'heard', 'hearing', 'play', 'plays', 'played', 'playing', 'run', 'runs', 'ran', 'running', 'move', 'moves', 'moved', 'moving', 'live', 'lives', 'lived', 'living', 'believe', 'believes', 'believed', 'believing', 'think', 'thinks', 'thought', 'thinking', 'know', 'knows', 'knew', 'knowing', 'want', 'wants', 'wanted', 'wanting', 'work', 'works', 'worked', 'working', 'use', 'uses', 'used', 'using', 'find', 'finds', 'found', 'finding', 'give', 'gives', 'gave', 'given', 'giving', 'tell', 'tells', 'told', 'telling', 'ask', 'asks', 'asked', 'asking', 'need', 'needs', 'needed', 'needing', 'feel', 'feels', 'felt', 'feeling', 'become', 'becomes', 'became', 'becoming', 'leave', 'leaves', 'left', 'leaving'}

# Tokenize the license text and count the occurrences of each word
words = re.findall(r'\b\w+\b', license_text.lower())
filtered_words = [word for word in words if word not in stop_words]
word_counts = Counter(filtered_words)

# Output the top 5 most frequently occurring words
top_words = word_counts.most_common(5)
for word, count in top_words:
    print(f'{word}: {count}')
