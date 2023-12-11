from bs4 import BeautifulSoup

def extractAndCleanAnchorTags(html):
    soup = BeautifulSoup(html, 'html.parser')
    anchor_tags = soup.find_all('a')
    cleaned_texts = []
    for tag in anchor_tags:
        text = tag.get_text()
        cleaned_text = text.replace('\u200c', '')
        cleaned_texts.append(cleaned_text)
    return cleaned_texts