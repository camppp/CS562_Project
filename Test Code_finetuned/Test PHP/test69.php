from bs4 import BeautifulSoup

def extractURLs(html):
    soup = BeautifulSoup(html, 'html.parser')
    urls = set()

    for tag in soup.find_all(['a', 'img','script']):
        if tag.name == 'a':
            urls.add(tag.get('href'))
        elif tag.name == 'img':
            urls.add(tag.get('src'))
        elif tag.name =='script':
            urls.add(tag.get('src'))

    return list(urls)