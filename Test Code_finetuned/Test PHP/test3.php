def findClosingTagPosition(html, element):
    start_tag = "<" + element
    end_tag = "</" + element + ">"
    start_pos = html.find(start_tag)
    if start_pos == -1:
        return -1
    end_pos = html.find(end_tag, start_pos)
    if end_pos == -1:
        return -1
    return end_pos + len(end_tag)