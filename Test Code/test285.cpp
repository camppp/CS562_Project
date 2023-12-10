python
def count_words_in_comments(code_snippet):
    comments = [line.strip()[2:].split() for line in code_snippet.split('\n') if line.strip().startswith('//')]
    word_counts = [len(comment) for comment in comments]
    return word_counts
