from bs4 import BeautifulSoup

def extract_plain_text(html_snippet: str) -> str:
    soup = BeautifulSoup(html_snippet, 'html.parser')
    plain_text = soup.get_text()
    return plain_text