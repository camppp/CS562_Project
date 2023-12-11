def word_count(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        words = content.split()
        word_counts = {}
        for word in words:
            if word in word_counts:
                word_counts[word] += 1
            else:
                word_counts[word] = 1
    return word_counts