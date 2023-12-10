python
import re

def count_keyword_occurrences_in_comments(file_path, keywords):
    keyword_counts = {keyword: 0 for keyword in keywords}
    in_comment = False
    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            if line.startswith('//'):
                for keyword in keywords:
                    keyword_counts[keyword] += line.lower().count(keyword.lower())
            if '/*' in line:
                in_comment = True
                for keyword in keywords:
                    keyword_counts[keyword] += line.lower().count(keyword.lower())
            if '*/' in line:
                in_comment = False
                for keyword in keywords:
                    keyword_counts[keyword] += line.lower().count(keyword.lower())
            if in_comment:
                for keyword in keywords:
                    keyword_counts[keyword] += line.lower().count(keyword.lower())
    return keyword_counts
