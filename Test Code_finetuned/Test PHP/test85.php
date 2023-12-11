from bs4 import BeautifulSoup

def countCSSLinks(html: str) -> int:
    soup = BeautifulSoup(html, 'html.parser')
    css_links = soup.find_all('link', rel='stylesheet')
    return len(css_links)